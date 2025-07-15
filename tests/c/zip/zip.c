#include <stdint.h>
#include <stdio.h>

#define ZIP_LFH_SIG 0x04034b50
#define ZIP2_LFH_SIG 0x04034b50

void IRSENTRY_MOCK_NOPARAMS() {}

int main(int argc, char **argv) {
  FILE *zip = fopen(argv[1], "rb");
  if (!zip) {
    return 1;
  }

  uint32_t signature;
  fread(&signature, sizeof(uint32_t), 1, zip);
  if (signature == ZIP_LFH_SIG) {
    uint64_t signature2;
    fread(&signature2, sizeof(uint64_t), 1, zip);
    if (signature2 == ZIP2_LFH_SIG) {
      IRSENTRY_MOCK_NOPARAMS();
    }
  }

  fclose(zip);
  return 0;
}
