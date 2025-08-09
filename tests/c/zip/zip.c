#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define ZIP_LFH_SIG 0x04034b50

struct ZIP_HEADER {
  uint32_t signature;
  uint16_t version;
  uint16_t flags;
  uint16_t compressionMethod;
  uint16_t lastModTime;
  uint16_t lastModDate;
  uint32_t crc32;
  uint32_t compressedSize;
  uint32_t uncompressedSize;
  uint16_t filenameLength;
  uint16_t extrafieldLength;
};

int main(int argc, char **argv) {
  FILE *zip = fopen(argv[1], "rb");
  if (!zip) {
    return 1;
  }

  struct ZIP_HEADER header;
  fread(&header, sizeof(struct ZIP_HEADER), 1, zip);
  if (header.signature != ZIP_LFH_SIG || header.version != ((uint16_t)0x14) ||
      header.compressionMethod != ((uint16_t)0x08)) {
    fclose(zip);
    return 0;
  }

  // BUFFER OVERFLOW
  char filename[128];
  fread(filename, sizeof(char), header.filenameLength, zip);
  printf("Filename: %s", filename);

  fclose(zip);
  return 0;
}
