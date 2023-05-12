#include <iostream>
using namespace std;

class Empty {
};

template <class T>
void wrapper(T &&obj) {
  // This code will always pass a LValue since obj is a local variable (&obj works)
  // checkValue(obj);
  // This code will pass the value type of T and not of the local variable.
  checkValue(forward<T>(obj));
  // Forward is done for this specific use case but a static_cast would also work. Alternative:
  // checkValue(static_cast<T>(obj));
}

void checkValue(Empty &obj) {
  cout << "Object is passed as Lvalue reference" << endl;
}

void checkValue(Empty &&obj) {
  cout << "Object is passed as Rvalue reference" << endl;
}
int main() {
  Empty object;

  // This should print a Lvalue
  wrapper(object);
  // This should print a Rvalue
  wrapper(Empty());

  return 0;
}