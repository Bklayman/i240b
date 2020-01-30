#include <cmath>

#include "fns-compare.hh"

static Float
nlg(Float n)
{
  const Float C = 1e4L;
  return n*C*log2(n);
}

static const bool isRegistered =
  register_fn(FnInfo("n lg", nlg));
