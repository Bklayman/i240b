#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <cstdlib>
#include <cstring>
#include <chrono>

#include "sorts.hh"

/** Return vector of n int's read from filePath into a[].  If filePath
 *  is "-" read from stdin.  If n < 0, read entire contents of file.
 */
static std::vector<int>
readIntsFromFile(const std::string filePath, int n)
{
  bool isStdin = filePath == "-";
  std::ifstream file;
  if (!isStdin) file.open(filePath);
  std::istream& in = (isStdin) ? std::cin : file;
  if (!in) {
    throw std::invalid_argument(std::string("cannot read ") + filePath +
				": " + std::strerror(errno));
  }
  std::vector<int> ints;
  for (int i = 0; n < 0 || i < n; ++i) {
    int v;
    in >> v;
    if (in.eof()) {
      if (n > 0) {
	std::cerr << "got eof on while reading " << filePath
		  << " after reading " << i << " ints; expected " << n
		  << std::endl;
	std::exit(1);
      }
      break;
    }
    ints.push_back(v);
  }
  return ints;
}

//type for pointer to a sorting function
using SortP = void (*)(int a[], int n);

//map algorithm name to corresponding function
struct Algorithm {
  std::string name;
  SortP sort;
};

static Algorithm algorithms[] = {
  { "insertionSort", insertionSort },
  { "bubbleSort", bubbleSort },
  { "selectionSort", selectionSort },
  { "mergeSort", mergeSort },
  { "quickSort", quickSort },
};

/** Return sorting function specified by name; terminate program
 *  if not valid.
 */
static SortP
getSort(std::string name)
{
  std::string names;
  for (auto i = 0u; i < sizeof(algorithms)/sizeof(algorithms[0]); ++i) {
    const std::string algName = algorithms[i].name;
    if (algName == name) return algorithms[i].sort;
    if (names.size() > 0) names += "|";
    names += algName;
  }
  std::cerr << "unknown algorithm " << name
	    << " must be one of " << names << std::endl;
  std::exit(1);
}

/** Output a line containing whitespace separated contents of a [0, n) */
static void
outArray(int a[], int n)
{
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}


static auto
go(SortP sort, std::string filePath, bool isVerbose, int nRead)
{
  std::vector<int> ints = readIntsFromFile(filePath, nRead);
  int* a = ints.data();
  int n = ints.size();
  auto t0 = std::chrono::high_resolution_clock::now();
  sort(a, n);
  auto t1 = std::chrono::high_resolution_clock::now();
  if (isVerbose) outArray(a, n);
  auto timeTaken = t1-t0;
  return timeTaken;
}

int
main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cerr << "usage: " << argv[0]
	      << " [-v] ALGORITHM INTS_DATA_FILE|- [N...]" << std::endl;
    std::exit(1);
  }
  bool isVerbose = std::strcmp(argv[1], "-v") == 0;
  bool nVerbose = (isVerbose) ? 1 : 0;
  const char* algorithm = argv[1 + nVerbose];
  const std::string filePath(argv[2 + nVerbose]);
  SortP sort = getSort(algorithm);
  int sizeArgsIndex = 3 + nVerbose;
  if (sizeArgsIndex == argc) {
    go(sort, filePath, isVerbose, -1);
  }
  else {
    std::cout << "n\ttime" << std::endl;
    for (int i = sizeArgsIndex; i < argc; ++i) {
      int nRead = atoi(argv[i]);
      auto timeTaken = go(sort, filePath, isVerbose, nRead);
      auto time = std::chrono::duration_cast<std::chrono::milliseconds>(timeTaken).count();
      std::cout << nRead << "\t" << time << std::endl;
    }
  }
}
