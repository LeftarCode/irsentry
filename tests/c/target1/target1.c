#include <assert.h>
#include <stdio.h>

struct A {
  int a, b;
  unsigned char *c;
  float f;
  double d;
};

void dangerousFunction(void) { printf("Dangerous function called!\n"); }

int testBitwiseOperations(int x, int y, float f, double d) {
  if (((x & 0x1F) == 0x1F) && (((y >> 4) & 1) == 1)) {
    dangerousFunction();
  } else {
    assert((x | y) != 0);
  }
  return x ^ y;
}

int main(void) {
  struct A a;
  a.a = 0x1F;
  a.b = 0x10;

  int result = testBitwiseOperations(a.a, a.b, a.f, a.d);

  printf("Result = %d\n", result);

  return 0;
}
