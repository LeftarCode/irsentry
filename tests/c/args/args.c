#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char buffer[64];

  if (strcmp(argv[1], "SecretPassword")) {
    IRSENTRY_MOCK_NOPARAMS();
  }

  return 0;
}
