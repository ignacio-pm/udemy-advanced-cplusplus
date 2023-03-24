#include <iostream>
#include <typeinfo>
using namespace std;

// A trailing return type can determine the return type depending on arguments.
// Auto can not inferred a return type so the trailing type is used as a return type.
// It can be useful for template functions by using decltype.
// Is declared with an auto return type and an arrow with a type after the function arguments.

// Function that multiplies 2 numbers of different types
template <class T, class S>
auto multiply2Numbers (T number1, S number2) -> decltype(number1*number2) {
  return number1*number2;
}
// Function that calls a function with two numbers and then adds one to the result
// template <class T, class S>
// auto functionPlus1 (T number1, S number2, T (* funct)(T, S)) -> decltype(funct()) {
//   return funct(number1, number2)+1;
// }
int main() {
  // Auto was already in C++ 98 but for default storage class. C++ 11 extends it to type declaration
  auto number = 5.5;
  auto text = "Text";

  // Auto returns char[] for input text or double for a decimal number
  // It could be better to still declare the type if a concrete type is desired (string / float) 
  cout << typeid(text).name() << endl;

  // Depending on the function arguments, the return type changes from double to int 
  cout << typeid(multiply2Numbers(3, number)).name() << endl;
  cout << typeid(multiply2Numbers(3, 6)).name() << endl;
  
  // cout << functionPlus1(number, 3, multiply2Numbers) << endl;

  return 0;
}