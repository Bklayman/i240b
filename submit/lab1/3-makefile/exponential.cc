#include <cmath>

#include "fns-compare.hh"

static Float
exponential(Float n)
{
  enum { B = 2, C = 10 };
  return C*pow(B, n);
}

static const bool isRegistered =
  register_fn(FnInfo("expn", exponential));
