#include <iostream>
#include <vector>

#include "fns-compare.hh"

std::vector<FnInfo>& fnInfoStore() {
  static std::vector<FnInfo> fnInfos;
  return fnInfos;
}

bool
register_fn(FnInfo fnInfo) {
  fnInfoStore().push_back(fnInfo);
  return true;
}

int
main() {
  FILE *const out = stdout;
  enum { N_WIDTH = 5, WIDTH = 9, PREC=2 };
  std::vector<FnInfo>& fnInfos = fnInfoStore();
  fprintf(out, "%*s", N_WIDTH, "n");
  for (auto &fnInfo : fnInfos) { fprintf(out, "%*s", WIDTH, fnInfo.descr); }
  fprintf(out, "\n");
  for (auto n : { 1.0L, 10.0L, 100.0L, 1000.0L, 10000.0L }) {
    fprintf(out, "%*Lg", N_WIDTH, n);
    for (auto &fnInfo : fnInfos) {
      fprintf(out, "%*.*Lg", WIDTH, PREC, fnInfo.fn(n));
    }
    fprintf(out, "\n");
  }
}
