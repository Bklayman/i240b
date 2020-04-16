#include <cctype>
#include <iostream>

#include "digit-sum.hh"

int
digitSum(const char* str)
{
  bool wantDigit = true;
  int acc = 0;
  for(const char* p = str; *p; ++p){
    int c = *p;
    if(isdigit(c)){
      if(wantDigit){
        acc+= *p - '0';
        wantDigit = false;
      } else {
        break;
      }
    } else if (c == '+') {
      if(wantDigit){
        break;
      }
      wantDigit = true;
    } else if (c != ' '){
      break;
    }
  }
  return acc;
}
