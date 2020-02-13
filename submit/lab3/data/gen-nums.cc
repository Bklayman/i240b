#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int
main(int argc, char* argv[])
{
  enum { MAX_NUM = 1000 };
  if (argc < 3) {
    std::cerr << "usage: " << argv[0] << " N_PER_FILE OUT_FILE..." << std::endl;
    std::exit(1);
  }
  int n = std::stoi(argv[1]); //no error checking
  for (auto file : std::vector<std::string>(&argv[2], &argv[argc])) {
    std::ofstream out(file);
    if (!out.is_open()) {
      std::cerr << "cannot write \"" << file << "\": "
		<< strerror(errno) << std::endl;
      std::exit(1);
    }
    for (int i = 0; i < n; i++) {
      //not the best way to get a rand in [0, MAX_NUM).
      out << rand() % MAX_NUM << std::endl;
    }
    out.close();
  }
}
