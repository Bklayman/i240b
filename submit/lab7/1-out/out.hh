#ifndef OUT_HH_
#define OUT_HH_

#include <algorithm>
#include <iostream>
#include <vector>


/** Output elements of [begin, end) on std::cout separated by single
 *  space.  The seqence of elements should be surrounded by [ and ]
 *  and terminated by a newline.
 */
template <typename Iterator>
void loopFn(Iterator begin, Iterator end, int arg) {
  std::cout << "[ ";
  for(auto p = begin; p != end; ++p){
    std::cout << *p << " ";
  }
  std::cout << "]" << std::endl;
}

/** Exactly like loopFn() but no loops should be used */
template <typename Iterator>
void noLoopFn(Iterator begin, Iterator end, int arg) {
  std::cout << "[ ";
  auto print = [](const int& i) { std::cout << i << " " ; };
  std::for_each(begin, end, print);
  std::cout << "]" << std::endl;
}

#endif //ifndef OUT_HH_
