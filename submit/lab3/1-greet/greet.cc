#include <iostream>
#include <cstdlib>
#include <cstring>

#define GREET "hello"


//Turn off compiler warnings about dumb bug in greetMsg()
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-local-addr"

static const char *
greetMsg(const char *name)
{
  const std::size_t len = strlen(GREET) + 1 + strlen(name);
  char msg[len + 1];
  strcpy(msg, GREET); strcat(msg, " "); strcat(msg, name);
  return msg;
}

#pragma GCC diagnostic pop  

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
