
// vulnerable.c
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Bufor o sta�ej wielko�ci 64 bajty
  char buffer[64];

  if (argc < 2) {
    printf("Usage: %s <text_to_copy>\n", argv[0]);
    return 1;
  }

  // PODATNO��: kopiujemy argv[1] bez sprawdzania d�ugo�ci -> mo�liwe
  // przepe�nienie bufora
  IRSENTRY_MOCK_NOPARAMS();

  printf("Skopiowano: %s\n", buffer);
  return 0;
}
