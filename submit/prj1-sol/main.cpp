#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>

//Returns an int corresponding to the error the inputs have
//0 - No errors
//1 - Not enough inputs
//2 - Bad input
//3 - MIN_WORD_LEN > MAX_WORD_LEN
int checkInputs(std::vector<std::string> args, int numArgs){
  if(numArgs < 4){
    std::cout << "usage: ./wordcounts MAX_N_OUT MIN_WORD_LEN MAX_WORD_LEN FILE...\n";
    return 1;
  }
  for(int i = 0; i < 3; i++){
    int input = std::stoi(args[i]);
    int intLength = 0;
    while(input != 0){
      intLength++;
      input /= 10;
    }
    if(intLength != args[i].length()){
      if(i == 0){
        std::cout << "bad integer value \"" << args[i] << "\" for MAX_N_OUT\n";
      } else if(i == 1) {
        std::cout << "bad integer value \"" << args[i] << "\" for MIN_WORD_LEN\n";
      } else {
        std::cout << "bad integer value \"" << args[i] << "\" for MAX_WORD_LEN\n";
      }
      return 2;
    }
  }
  if(std::stoi(args[1]) > std::stoi(args[2])){
    std::cout << "MIN_WORD_LEN " << args[1] << " is greater than MAX_WORD_LEN " << args[2] << "\n";
    return 3;
  }
  return 0;
}

std::unordered_map<std::string, int> getWordCounts(std::vector<std::string> args){
  std::unordered_map<std::string, int> wordCounts;
  for(int i = 3; i < args.size(); i++){
    std::ifstream in(args[i]);
    while(in.good()){
      std::string word;
      in >> word;
      for(int j = 0; j < word.length(); j++){
        if(word.at(j) > 64 && word.at(j) < 91){
          word = word.substr(0, j) + (char)(word.at(j) + 32) + word.substr(j + 1, word.length() - j - 1);
        } else if (word.at(j) < 97 || word.at(j) > 122){
          word = word.substr(0, j) + word.substr(j + 1, word.length() - j - 1);
          j--;
        }
      }
      wordCounts[word]++;
    }
    if(!in.eof()){
      std::cout << "error reading file " << args[i] << "\n";
    }
  }
  return wordCounts;
}

int main(int argc, char* argv[]){
  std::vector<std::string> args;
  for(int i = 1; i < argc; i++){
    args.push_back(argv[i]);
  }
  int errorCheck = checkInputs(args, argc - 1);
  if(errorCheck != 0){
    return 1;
  }
  std::unordered_map<std::string, int> wordCounts = getWordCounts(args);
}
