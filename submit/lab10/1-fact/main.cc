#include <iostream>

#include "fact.hh"

int main(int argc, const char* argv[]) {
  for (int i = 1; i < argc; ++i) {
    int n = std::atoi(argv[i]);
    std::cout << fact(n) << std::endl;
  }
}
