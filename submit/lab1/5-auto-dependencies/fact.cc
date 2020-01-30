#include "fns-compare.hh"

static Float
factorial(Float n)
{
  enum { C = 1 };
  auto f = 1.0;
  for (auto i = 1; i <= n; i++) f *= i;
  return C*f;
}

static const bool isRegistered =
  register_fn(FnInfo("fact", factorial));
