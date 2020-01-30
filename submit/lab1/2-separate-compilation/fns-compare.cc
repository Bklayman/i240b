#include <iostream>
#include <vector>

#include "fns-compare.hh"

std::vector<FnInfo>& fnInfoStore() {
  static std::vector<FnInfo> fnInfos;
  return fnInfos;
}

static double
linear(double n)
{
  enum { C = 10000 };
  return C*n;
}

static const bool isRegistered =
  register_fn(FnInfo("linear", linear));

static double
quadratic(double n)
{
  const double C = 1e3;
  return C*n*n;
}

bool
register_fn(FnInfo fnInfo) {
  fnInfoStore().push_back(fnInfo);
  return true;
}

int
main() {
  FILE *const out = stdout;
  enum { WIDTH = 10 };
  std::vector<FnInfo>& fnInfos = fnInfoStore();
  fprintf(out, "%*s", WIDTH, "n");
  for (auto &fnInfo : fnInfos) { fprintf(out, "%*s", WIDTH, fnInfo.descr); }
  fprintf(out, "\n");
  for (auto n : { 1.0, 10.0, 100.0, 1000.0, 10000.0, 100000.0 }) {
    fprintf(out, "%*g", WIDTH, n);
    for (auto &fnInfo : fnInfos) { fprintf(out, "%*g", WIDTH, fnInfo.fn(n)); }
    fprintf(out, "\n");
  }
}
