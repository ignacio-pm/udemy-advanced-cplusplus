#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
  string text = "Text";

  // Typeid (C++ 98) allows to return the type of the variable with name mangling (information is 
  // added to the type in order to identify if the type was overloaded / is included in a class...)
  cout << typeid(text).name() << endl;

  // New in C++ 11: Declare a variable with the type of another variable
  decltype(text) anotherText = "Another text";

  cout << "Type of " << anotherText << " is: " << typeid(anotherText).name() << endl;
  return 0;
}