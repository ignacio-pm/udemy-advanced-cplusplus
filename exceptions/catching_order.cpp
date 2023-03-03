#include <iostream>
#include <exception>
using namespace std;

void goesWrong() {
  bool badAllocError = true;
  bool exceptionError = false;
  if (badAllocError) {
    throw bad_alloc();
  } if (exceptionError) {
    throw exception();
  }
}
int main() {
  try {
    goesWrong();
  // Catch child classes before the parent class.
  } catch(bad_alloc &e) {
    cout << "Caught bad_alloc: " << e.what() << endl;
  } catch(exception &e) {
    cout << "Caught exception: " << e.what() << endl;
  }
  return 0;
}