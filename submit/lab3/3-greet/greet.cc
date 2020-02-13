#include <iostream>
#include <cstdlib>
#include <cstring>

#define GREET "hello"

static std::string
greetMsg(const char *name)
{
  std::string greeting = std::string(GREET) + " " + std::string(name);
  std::cout << "Greeting's size: " << sizeof(greeting) << "\n";
  return greeting;
}

int 
main(int argc, const char *argv[])
{
  if (argc == 1) {
    std::cerr << "usage: " << argv[0] << " NAME..." << std::endl;
    std::exit(1);
  }
  else {
    for (int i = 1; i < argc; i++) {
      std::cout << greetMsg(argv[i]) << std::endl;
    }
  }
}
