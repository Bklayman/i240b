#include "fns-compare.hh"

static double
linear(double n)
{
  enum { C = 10000 };
  return C*n;
}

static const bool isRegistered =
  register_fn(FnInfo("linear", linear));
