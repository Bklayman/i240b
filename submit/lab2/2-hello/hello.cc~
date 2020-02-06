#include <locale>
#include <iostream>
#include <cstdlib>
#include <cstring>

/** Upcase the initial letter of each word from in, copying the
 *  results into out.  The caller is responsible to ensure that out
 *  has enough space for the strlen(in) characters of in.
 */
void
upcaseWords(const char in[], char out[])
{
  bool inWord = false;
  const int n = std::strlen(in);
  for (int i = 0; i < n; i++) {
    if (!inWord && std::isalpha(in[i])) {
      out[i] = std::toupper(in[i]);
    }
    else {
      out[i] = in[i];
    }
    inWord = std::isalpha(in[i]);
  }
}

static void
sayHello(const char *name)
{
  std::cout << "Hello " << name << std::endl;
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
      const char *name = argv[i];
      char friendlyName[strlen(name)];
      upcaseWords(name, friendlyName);
      sayHello(friendlyName);
    }
  }
}
