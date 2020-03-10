#include "arrayseq.hh"
#include "command.hh"
#include "dlinkseq.hh"
#include "seq.hh"

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>

using TestType = int;

void readInts(char* fileName, Seq<TestType>* sequence){
  std::ifstream in(fileName);
  while(in.good()){
    std::string number;
    in >> number;
    if(number != ""){
      sequence->push(std::stoi(number));
    }
  }
}

void outputData(Seq<TestType>* sequence){
  ConstIterPtr<TestType> beginPoint = sequence->cbegin();
  ConstIterPtr<TestType> endPoint = sequence->cend();
  ConstIter<TestType>& p2 = *endPoint;
  for (ConstIter<TestType>& p1 = *beginPoint; p1; ++p1) {
    std::cerr << *p1 << std::endl << *p2 << std::endl;
    --p2;
  }
}

int main(int argc, char* argv[]){
  char* fileName;
  bool aDash = false;
  if(argc < 2){
    std::cerr << "usage: " << argv[0] << " [-a] INTS_FILE_PATH" << std::endl;
    std::exit(1);
  } else if (argc == 3){
    if(strncmp(argv[1], "-a", 2) != 0){
      std::cerr << "usage: " << argv[0] << " [-a] INTS_FILE_PATH" << std::endl;
      std::exit(1);
    }
    aDash = true;
    fileName = argv[2];
  } else {
    fileName = argv[1];
  }
  SeqPtr<TestType> testerPointer;
  if(aDash){
    testerPointer = ArraySeq<TestType>::make();
  } else {
    testerPointer = DLinkSeq<TestType>::make();
  }
  Seq<TestType>* sequence = testerPointer.get();
  readInts(fileName, sequence);
  outputData(sequence);
}
