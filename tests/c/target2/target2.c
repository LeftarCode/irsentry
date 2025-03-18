#include <stdio.h>

int complicatedFunction(int x, int y, int z) {
  int val = (x / 10) + (y / 10) - (z / 10);

  if (x > 100 && y < 1000000) {
    if (z % 2 == 0) {
      val += 1;
    } else {
      val -= 1;
    }
  } else {
    val = x - y + z;
  }

  if (val > 1000) {
    return 2;
  } else if (val < -1000) {
    return -2;
  } else {
    return 0;
  }
}

int checkLimits(int a, int b) {
  if (a < 0) {
    return -1;
  } else if (b < a) {
    return -2;
  } else if ((a + b) > 300000000) {
    return 99;
  }
  return 1;
}

int main(void) {
  int a = 1000000000;
  int b = 2000000000;
  int c = 314159265;
  int d = -1;
  int e = 0;

  if ((a > 0) && (b > a) && (b - a == 1000000000) && (c % 10 == 5) &&
      (d < 0 || e == 0) && complicatedFunction(a, b, c) == 2 &&
      checkLimits(a, b) == 99) {
    long long result = (long long)a * b;
    printf("%lld\n", result);

    if (result < 0) {
      printf("%d\n", d - e);
    }
  } else {
    int tmp = (a + b + c + d + e) / 2;
    if (tmp > 0) {
      if (tmp % 2 == 0) {
        tmp = -tmp;
      } else {
        tmp += 5;
      }
    }
    printf("%d\n", tmp);
  }

  return 0;
}
