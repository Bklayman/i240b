#ifndef FNS_COMPARE_H_
#define FNS_COMPARE_H_

typedef double FN(double);

struct FnInfo {
  FnInfo(const char *descr, FN *fn) : descr(descr), fn(fn) { }
  const char *descr;
  FN *fn;
};

bool register_fn(const FnInfo fnInfo); 

#endif
