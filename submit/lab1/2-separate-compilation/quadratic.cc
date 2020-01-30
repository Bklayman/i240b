#include <iostream>
#include "fns-compare.hh"

static double
quadratic(double n)
{
  const double C = 1e3;
  return C*n*n;
} 
 
static double 
linear(double n) 
{ 
  enum { C = 10000 }; 
  return C*n; 
} 
 
static const bool isRegistered = 
  register_fn(FnInfo("linear", linear));
