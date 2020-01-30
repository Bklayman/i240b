#ifndef FNS_COMPARE_H_
#define FNS_COMPARE_H_

/** use long double to minimize overflow */
typedef float Float;  

/** type of a complexity function */
typedef Float FN(Float);

/** information for a complexity function */
struct FnInfo {
  FnInfo(const char *descr, FN *fn) : descr(descr), fn(fn) { }
  const char *descr;
  FN *fn;
};

/** function used to register information for a complexity function */
bool register_fn(const FnInfo fnInfo); 

#endif
