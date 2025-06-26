#include <stdio.h>
#include <string.h>

void IRSENTRY_MOCK_NOPARAMS() { printf("TRAFIONY!\n"); }

int main(int argc, char *argv[]) {
  char *buffer = 0;

  if (strcmp(argv[1], "SecretPassword") == 0) {
    if (strcmp(argv[2], "d6RzqyPr3mIv7i7gd4gyADAn6MlC5FNo") == 0) {
      IRSENTRY_MOCK_NOPARAMS();
    }
  }

  return 0;
}
