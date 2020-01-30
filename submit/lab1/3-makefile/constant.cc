#include "fns-compare.hh"

static Float
constant(Float n)
{
  const double C = 1e7L;
  return C;
}

static const bool isRegistered =
  register_fn(FnInfo("constant", constant));
