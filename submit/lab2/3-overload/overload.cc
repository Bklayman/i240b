#include <iostream>

int f(int *a) { return *a * 2; }
int f(int a) { return a + 1;}
int f(int a, int b) { return a - b; }

int
main() {
  int a = 2;
  int b = 3;
  std::cout 
    << "f(a) = " << f(a)
    << "; f(&a) = " << f(&a)
    << "; f(a, b) = " << f(a, b)
    << std::endl;
}
