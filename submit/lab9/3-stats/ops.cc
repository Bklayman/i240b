#include "ops.hh"

/** return < 0, == 0, > 0 if a < b, a == b, a > b */
int
Ops::compare(int a, int b) {
  return a - b;
}

/** swap a[i] and a[j] */
void
Ops::swap(int a[], int i, int j)
{
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}


