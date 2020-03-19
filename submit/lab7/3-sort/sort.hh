#ifndef OUT_HH_
#define OUT_HH_

#include <algorithm>
#include <vector>

template <typename Iterator>
void
outContainer(Iterator begin, Iterator end) 
{
  std::cout << "[ ";
  auto print = [](const int& i) { std::cout << i << " " ; };
  std::for_each(begin, end, print);
  std::cout << "]" << std::endl;
}

template <typename Iterator>
void loopFn(Iterator begin, Iterator end, int arg) {
  std::sort(begin, end);
  outContainer(begin, end);
}

/** Exactly like loopFn() but no loops should be used */
template <typename Iterator>
void noLoopFn(Iterator begin, Iterator end, int arg) {
  loopFn<Iterator>(begin, end, arg);
}


#endif //ifndef OUT_HH_
