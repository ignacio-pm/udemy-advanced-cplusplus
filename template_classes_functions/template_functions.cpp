#include <iostream>
using namespace std;

// template <typedef T> is equivalent to template <class T> 

// Function that prints the variable value with cout
template <class T>
void print(T var) {
  cout << var << endl;
  // The type of a sentence is an array of characters or a string if type is given to the function
  cout << typeid(var).name() << endl;
}

int main() {
  // The type of the template class can be inferred or passed to the function
  print("Any type that with a << operator implementation can be printed here");
  print<string>("This sentence is passed as a string");

  return 0;
}