#include <stdio.h>
#include <string.h>

void IRSENTRY_MOCK_NOPARAMS() { printf("TRAFIONY!\n"); }

int main(int argc, char *argv[]) {
  char buffer[64];

  if (strcmp(argv[1], "SecretPassword") == 0) {
    if (strcmp(argv[2], "SecretPassword2") == 0) {
      IRSENTRY_MOCK_NOPARAMS();
    }
  }

  return 0;
}
