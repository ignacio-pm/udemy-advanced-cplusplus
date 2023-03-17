#include <iostream>
using namespace std;

// Functor is a class or struct object that can be called as a function. In order to achieve that 
// the function-call () operator is overloaded. Advantages of functors against function pointers are
// that they, as class objects, can hold internal states in variables and
// the compiler can inline them (replace a call to a function with its contents).
// This means that the target function (operator()) is known at compile time (not only its address)

// Abstract struct that forces its child structs to override the () operator
struct MatchString {
  // Returns true if the text matches an specific desired text
  virtual bool operator()(string &text) = 0;
};

struct MatchAlloc: public MatchString {
  virtual bool operator()(string &text) {
    return text == "bad_alloc";
  }
};

struct MatchLength: public MatchString {
  virtual bool operator()(string &text) {
    return text == "length_error";
  }
};

struct MatchBadException: public MatchString {
  virtual bool operator()(string &text) {
    return text == "bad_exception";
  }
};

// Function that prints the result of applying an input functor on the input variable text
void printException (string text, MatchString &functor) {
  if(functor(text)) {
    cout << "The expected exception was found: " << text << endl;
  } else {
    cout << "The exception was not expected" << endl;
  }
}

int main() {
  // Instantiation of functors, child structs of MatchString
  MatchAlloc allocFunc;
  MatchBadException badFunc;
  MatchLength lengthFunc;
  string badAlloc = "bad_alloc";

  // Calling the functors with or without an external function
  cout << allocFunc(badAlloc) << endl;
  printException("length_error", lengthFunc);
  printException("length_error", badFunc);
  
  return 0;
}