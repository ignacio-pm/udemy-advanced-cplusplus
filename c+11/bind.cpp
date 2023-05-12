#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;

class Number {
  static int count;
  int _number;
public:
  Number(int number): _number(number) {
    count++;
  }
  int multiplyAndAdd(int n1, int n2) {
    return (_number * n1) + n2;
  }
  static int getCount() {
    return count;
  }
  // Static constructors are not allowed in C++ but variables can be set in methods
  static void restartCount(int newCount) {
    count = newCount;
  }
};

// Function that returns the sum of the 3 arguments
int add(int n1, int n2, int n3) {
  return n1 + n2 + n3;
}

// Static variable cannot be initialized inside its class or a function (main) but in global scope
int Number::count = 0;

int main() {
  Number number(5);

  // Bind a function and set fixed parameters
  auto calculateUntil3 = bind(add, 1, 2, 3);
  cout << calculateUntil3() << endl;

  // Bind a function but let the parameter open
  auto calculateWithParameters = bind(add, placeholders::_1, _2, _3);
  cout << calculateWithParameters(4, 5, 6) << endl;

  // Bind a method with parameters in another order. It is necessary to pass a class object
  auto multAddCalculate = bind(&Number::multiplyAndAdd, number, _2, _1);
  cout << multAddCalculate(3, 2) << endl;

  // For static methods, no object is passed
  auto newCount = bind(&Number::restartCount, _1);
  auto getCount = bind(&Number::getCount);
  newCount(3);
  cout << getCount() << endl;

  return 0;
}