#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>

#include <deque>
#include <forward_list>
#include <list>
#include <set>
#include <vector>

#include <cstdlib>
#include <cstring>

#include "find.hh"

/** Return vector of int's read from filePath.  If filePath is
 *  "-" read from stdin.
 */
static std::vector<int>
readIntsFromFile(const std::string filePath)
{
  bool isStdin = filePath == "-";
  std::ifstream fstream;
  if (!isStdin) fstream.open(filePath);
  std::istream& in = (isStdin) ? std::cin : fstream;
  if (!in) {
    throw std::invalid_argument(std::string("cannot read ") + filePath +
				": " + std::strerror(errno));
  }
  //construct a vector from an istream_iterator on istream in.
  //The two arguments give the begin and end of the iterator.
  std::vector<int> ints((std::istream_iterator<int>(in)),
			std::istream_iterator<int>());
  //no in.close(); depend on RAII
  return ints;
}


static void
go(std::string containerSpec, std::vector<int> ints, int arg)
{
  if (containerSpec == "[]") {
    int elements[ints.size()];
    for(int i = 0; i < ints.size(); i++){
      elements[i] = ints[i];
    }
    loopFn(elements, &elements[ints.size()], arg);
    noLoopFn(elements, &elements[ints.size()], arg);
  }
  else if (containerSpec == "deque") {
    std::deque<int> container(ints.begin(), ints.end());
    loopFn(container.begin(), container.end(), arg);
    noLoopFn(container.begin(), container.end(), arg);
  }
  else if (containerSpec == "forward_list") {
    std::forward_list<int> container(ints.begin(), ints.end());
    loopFn(container.begin(), container.end(), arg);
    noLoopFn(container.begin(), container.end(), arg);
  }
  else if (containerSpec == "list") {
    std::list<int> container(ints.begin(), ints.end());
    loopFn(container.begin(), container.end(), arg);
    noLoopFn(container.begin(), container.end(), arg);
  }
  else if (containerSpec == "multiset") {
    std::multiset<int> container(ints.begin(), ints.end());
    loopFn(container.begin(), container.end(), arg);
    noLoopFn(container.begin(), container.end(), arg);
  }
  else if (containerSpec == "set") {
    std::set<int> container(ints.begin(), ints.end());
    loopFn(container.begin(), container.end(), arg);
    noLoopFn(container.begin(), container.end(), arg);
  }
  else if (containerSpec == "vector") {
    loopFn(ints.begin(), ints.end(), arg);
    noLoopFn(ints.begin(), ints.end(), arg);
  }
  else {
    std::cerr << "unknown container " << containerSpec << std::endl;
    std::exit(1);
  }
}

static void
usage(std::string progName) {
  std::cerr << "usage: "
	    << progName
	    << " CONTAINER_SPEC INTS_DATA_FILE [INT]"
	    << std::endl;
  std::exit(1);
}


int
main(int argc, char* argv[])
{
  try {
    if (argc != 3 && argc != 4) usage(argv[0]);
    const std::string containerSpec(argv[1]);
    const std::string filePath(argv[2]);
    std::vector<int> ints = readIntsFromFile(filePath);
    const int arg = (argc == 4) ? atoi(argv[3]) : 0;
    go(containerSpec, ints, arg);
  }
  catch (const std::exception& err) {
    std::cerr << err.what() << std::endl;
  }

}
