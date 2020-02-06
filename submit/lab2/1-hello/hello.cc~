#include <iostream>
#include <cstdlib>

static void
sayHello(const char *name)
{
  std::cout << "hello " << name << std::endl;
}

int 
main(int argc, const char *argv[])
{
  if (argc == 1) {
    std::cerr << "usage: " << argv[0] << " NAME..." << std::endl;
    std::exit(1);
  }
  else {
    for (int i = 1; i <= argc; i++) {
      sayHello(argv[i]);
    }
  }
}
