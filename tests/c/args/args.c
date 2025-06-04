
// vulnerable.c
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Bufor o sta³ej wielkoœci 64 bajty
  char buffer[64];

  if (argc < 2) {
    printf("Usage: %s <text_to_copy>\n", argv[0]);
    return 1;
  }

  // PODATNOŒÆ: kopiujemy argv[1] bez sprawdzania d³ugoœci -> mo¿liwe
  // przepe³nienie bufora
  IRSENTRY_MOCK_NOPARAMS();

  printf("Skopiowano: %s\n", buffer);
  return 0;
}
