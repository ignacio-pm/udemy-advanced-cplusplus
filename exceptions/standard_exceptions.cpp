#include <iostream>
using namespace std;

class BigArray {
  public:
    BigArray() {
      // bad_alloc is thrown due to memory can not be allocated
      char *p_array = new char [999999999999999999];
      delete []p_array;
    }
};

int main() {
  try {
    BigArray array;
  } catch (bad_alloc &e) {
    cout << "Exception caught: " << e.what() << endl;
  }
  cout << "Program continues even after exception was thrown" << endl;
  return 0;
} 