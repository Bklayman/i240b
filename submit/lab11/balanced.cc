#include <cstring>
#include <iostream>

class Stack{
private:
  int stk[16];
  int stkIndex = 0;

public:
  void push(int num){
    if(stkIndex < 16){
      stk[stkIndex] = num;
      stkIndex++;
    } else {
      std::cout << "ERROR: Trying to push onto a full stack" << std::endl;
      exit(1);
    }
  }

  int pop(){
    if(stkIndex > 0){
      stkIndex--;
      return stk[stkIndex];
    } else {
      std::cout << "ERROR: Trying to pop an empty stack" << std::endl;
      exit(1);
    }
  }

  int size(){
    return stkIndex;
  }

};

struct DelimMap {
  int delim;
  int encoding;
};

DelimMap delimEncodings[] = {
  { '(', 1},
  { ')', -1},
  { '[', 2},
  { ']', -2},
  { '<', 3},
  { '>', -3},
  { '{', 4},
  { '}', -4}
};

int chkDelim(int delim){
  for(int i = 0; i < 8; i++){
    if(delim == delimEncodings[i].delim){
      return delimEncodings[i].encoding;
    }
  }
  return -42;
}

int main(int argc, char** argv){
  Stack delims;
  for(int i = 1; i < argc; i++){
    if(strlen(argv[i]) != 1){
      std::cout << "ERROR: Input delimiter " << argv[i] << " not of length one at argument " << i << std::endl;
      exit(1);
    }
    int check = chkDelim(argv[i][0]);
    if(check == -42){
      std::cout << "ERROR: Invalid delimeter " << argv[i][0] << " at argument " << i << std::endl;
      exit(1);
    }
    if(check > 0){
      delims.push(argv[i][0]);
    } else {
      int closeDelim = delims.pop();
      int checkClose = chkDelim(closeDelim);
      if(checkClose != -1 * check){
        std::cout << "ERROR: Unbalanced delimiter at argument " << i << std::endl;
        exit(1);
      }
    }
  }
  if(delims.size() != 0){
    std::cout << "ERROR: Unbalanced final stack of delimiters" << std::endl;
    exit(1);
  }
  return 0;
}
