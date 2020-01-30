#include "fns-compare.hh"

static Float
quadratic(Float n)
{
  Float C = 1e2L;
  return C*n*n*n;
}


static const bool isRegistered =
  register_fn(FnInfo("cubic", quadratic));
