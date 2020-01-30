#include <iostream>

static double
linear(double n)
{
  const double C = 1e5;
  return C*n;
}

static double
quadratic(double n)
{
  const double C = 1e3;
  return C*n*n;
}


int
main() {
  FILE *const out = stdout;
  for (auto n : { 1.0, 10.0, 100.0, 1000.0, 10000.0 }) {
    fprintf(out, "%g %g\n", n, linear(n));
  }
}

