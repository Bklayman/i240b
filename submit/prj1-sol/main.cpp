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


//Returns and unordered_map with the words within the word lengths as keys and the frequencies as values
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
      if(word.length() >= std::stoi(args[1]) && word.length() <= std::stoi(args[2])){
        wordCounts[word]++;
      }
    }
    if(!in.eof()){
      std::cout << "error reading file " << args[i] << "\n";
    }
  }
  return wordCounts;
}

std::vector<std::string> getKeys(std::unordered_map<std::string, int> wordCounts){
  std::vector<std::string> keys(wordCounts.size());
  for(auto key : wordCounts){
    keys.push_back(key.first);
  }
  return keys;
}

std::vector<std::string> sortKeysByName(std::unordered_map<std::string, int> wordCounts, std::vector<std::string> keys){
  for(int i = 0; i < keys.size() - 1; i++){
    for(int j = i + 1; j < keys.size(); j++){
      if(wordCounts[keys[i]] != wordCounts[keys[j]]){
        break;
      }
      if(keys[i].compare(keys[j]) > 0){
        std::string temp = keys[i];
        keys[i] = keys[j];
        keys[j] = temp;
      }
    }
  }
  return keys;
}

std::vector<std::string> sortKeys(std::unordered_map<std::string, int> wordCounts, std::vector<std::string> keys){
  for(int i = 0; i < keys.size() - 1; i++){
    for(int j = i + 1; j < keys.size(); j++){
      if(wordCounts[keys[i]] < wordCounts[keys[j]]){
        std::string temp = keys[i];
        keys[i] = keys[j];
        keys[j] = temp;
      }
    }
  }
  return sortKeysByName(wordCounts, keys);
}

void printFinalValues(int MAX_N_OUT, std::vector<std::string> keys, std::unordered_map<std::string, int> wordCounts, int numKeys){
  for(int i = 0; i < MAX_N_OUT && i < numKeys; i++){
    std::cout << keys[i] << ": " << wordCounts[keys[i]] << "\n";
  }
}

int getNumKeys(std::unordered_map<std::string, int> wordCounts){
  int counter = 0;
  for(auto key : wordCounts){
    counter++;
  }
  return counter;
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
  std::vector<std::string> keys = getKeys(wordCounts);
  keys = sortKeys(wordCounts, keys);
  int numKeys = getNumKeys(wordCounts);
  printFinalValues(std::stoi(args[0]), keys, wordCounts, numKeys);
}
