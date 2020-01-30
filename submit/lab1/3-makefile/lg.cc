#include <cmath>

#include "fns-compare.hh"

static Float
lg(Float n)
{
  const Float C = 1e6L;
  return C*log2(n);
}

static const bool isRegistered =
  register_fn(FnInfo("log2", lg));
