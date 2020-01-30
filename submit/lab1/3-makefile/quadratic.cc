#include "fns-compare.hh"

static Float
quadratic(Float n)
{
  Float C = 1e3L;
  return C*n*n;
}


static const bool isRegistered =
  register_fn(FnInfo("quadr", quadratic));
