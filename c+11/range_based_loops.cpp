#include <iostream>
using namespace std;

int main() {
  // C++ 11 bracket initialization
  string texts[]{"one", "two", "three", "four"};

  // In range-based loop the object is directly given (not the index)
  // Auto can be used to handle with different types (char, strings) and long types (e.g. iterators)
  for (auto text: texts) {
    for (auto c: text) {
      cout << c << ", " << flush;
    }
    cout << endl;
  }

  return 0;
}