#include "digit-sum.hh"

#include <iostream>
int
main(int argc, char* argv[])
{

  for (int i = 1; i < argc; ++i) {
    std::cout << digitSum(argv[i]) << std::endl;
  }
  
}
