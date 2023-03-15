#include <iostream>
using namespace std;

// Function that prints the variable value and type
template <class T>
void print(T var) {
  // Template function prints also the type
  cout << "Type: " << typeid(var).name() << " Value: " << var << endl;
}
// Function that prints the variable value 
void print(int var) {
  cout << var << endl;
}
// Function that initialize a variable of the type given to the function (type is obligatory)
template <class T>
T initialize() {
  return T();
}

int main() {
  print(6);
  // print <>(5) is equivalent in this example
  print<int>(5);

  print<>(initialize<int>());
  // The following line throws an error because the type is not passed to the function
  // initialize();

  return 0;
}