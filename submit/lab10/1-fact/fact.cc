#include "fact.hh"

unsigned fact(unsigned n) {
  if(n < 0){
    return 0;
  }
  return (n == 1 || n == 0) ? 1 : n * fact(n - 1);
}
