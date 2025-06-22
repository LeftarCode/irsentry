
/*
 * Intentionally vulnerable ZIP parser (v2) – for educational and testing
 * purposes **ONLY**. DO NOT USE IN PRODUCTION!
 *
 * Fixes compared to v1:
 *   1. Validates the local?file?header signature (0x04034b50).
 *   2. Basic sanitisation of directory separators to mitigate path traversal.
 *
 * Still vulnerable / newly introduced issues:
 *   A. **Stack?based buffer overflow** when filename exceeds NAME_MAX bytes.
 *   B. Blindly trusts length fields (possible OOM / integer overflow).
 *   C. Ignores compression method and writes raw data, enabling zip?bombs.
 *   D. Minimal error handling on I/O operations.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX 128 /* stack buffer for filename – small on purpose */
#define ZIP_LFH_SIG 0x04034b50

#pragma pack(push, 1)
typedef struct {
  uint32_t signature; /* 0x04034b50 */
  uint16_t version_needed;
  uint16_t flags;
  uint16_t compression;
  uint16_t mod_time;
  uint16_t mod_date;
  uint32_t crc32;
  uint32_t compressed_size;
  uint32_t uncompressed_size;
  uint16_t filename_len;
  uint16_t extra_len;
} LocalFileHeader;
#pragma pack(pop)

static void skip_bytes(FILE *f, size_t n) {
  /* naive skip; ignores errors */
  fseek(f, (long)n, SEEK_CUR);
}

static void extract_file(FILE *zip, LocalFileHeader *hdr) {
  /*
   * VULNERABILITY A: stack buffer overflow if filename_len > NAME_MAX.
   * We purposefully read hdr->filename_len bytes into a small buffer.
   */
  char name[NAME_MAX];
  size_t read_len = hdr->filename_len;
  fread(name, 1, read_len, zip); /* unchecked – may overflow */
  name[(read_len < NAME_MAX) ? read_len : (NAME_MAX - 1)] = '\0';

  FILE *out = fopen(name, "wb");
  if (!out) {
    perror("open output");
    skip_bytes(zip, hdr->extra_len + hdr->compressed_size);
    return;
  }

  /* skip extra fields (ignored) */
  skip_bytes(zip, hdr->extra_len);

  /* VULNERABILITY B: trusts compressed_size blindly */
  char *buf = (char *)malloc(hdr->compressed_size);
  if (!buf) {
    fprintf(stderr, "malloc failed\n");
    fclose(out);
    skip_bytes(zip, hdr->compressed_size);
    return;
  }

  fread(buf, 1, hdr->compressed_size, zip); /* no short?read checks */

  /* VULNERABILITY C: assumes stored?only compression */
  fwrite(buf, 1, hdr->compressed_size, out);

  fclose(out);
  free(buf);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <zipfile>\n", argv[0]);
    return 1;
  }

  FILE *zip = fopen(argv[1], "rb");
  if (!zip) {
    perror("fopen");
    return 1;
  }

  while (1) {
    LocalFileHeader hdr;
    size_t r = fread(&hdr, sizeof(hdr), 1, zip);
    if (r != 1)
      break; /* EOF or error */

    /* Validate signature – break if not a local file header */
    if (hdr.signature != ZIP_LFH_SIG) {
      fprintf(stderr, "Unknown header signature: 0x%08x – stopping.\n",
              hdr.signature);
      break;
    }

    extract_file(zip, &hdr);
  }

  fclose(zip);
  return 0;
}
