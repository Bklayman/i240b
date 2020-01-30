#include "fns-compare.hh"

static Float
linear(Float n)
{
  const Float C = 1e5;
  return C*n;
}

static const bool isRegistered =
  register_fn(FnInfo("linear", linear));
