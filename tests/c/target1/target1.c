#include <stdio.h>

double c = -5.689;

int main() {
  const char* test = "TEST!";
  int a = 1000;
  if (a > 100) {
    printf(&test[4]);
    c++;
  }
  printf("TEST%n\n", &a);
  return 0;
}
