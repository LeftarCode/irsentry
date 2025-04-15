
void use(int);
int getA();
int getB();

void phi_demo(bool isTrue) {
  int x;
  if (isTrue) {
    x = getA();
  } else {
    x = getB();
  }

  use(x);
}
