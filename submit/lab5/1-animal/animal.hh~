#include <string>

class Animal {
public:
  Animal(std::string name) : name(name) {}
  virtual ~Animal() {}

  virtual std::string says()  const = 0;
  const std::string name;

  
};

class Dog : public Animal {
public:
  Dog(std::string name) : Animal(name) {}

  std::string says() const {
    return "woof";
  }
  
};

class Cat : public Animal {
public:
  Cat(std::string name) : Animal(name) {}

  std::string says() const {
    return "meow";
  }
  
};

class Cow : public Animal {
public:
  Cow(std::string name) : Animal(name) {}

  std::string says() const {
    return "moo";
  }
  
};
  
  
  
  
