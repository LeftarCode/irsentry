#include <assert.h>
#include <stdio.h>

void dangerousFunction(void) { printf("Dangerous function called!\n"); }

int testBitwiseOperations(int x, int y) {
  if (((x & 0x1F) == 0x1F) && (((y >> 4) & 1) == 1)) {
    dangerousFunction();
  } else {
    assert((x | y) != 0);
  }
  return x ^ y;
}

int main(void) {
  int a = 0x1F;
  int b = 0x10;

  int result = testBitwiseOperations(a, b);

  printf("Result = %d\n", result);

  return 0;
}
