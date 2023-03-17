#include <iostream>
using namespace std;

// Function that prints the variable value 
void print(int var) {
  cout << var << endl;
}

int main() {
  // Initialize a function pointer
  void (*pPrint)(int) = print;
  pPrint(5);

  // Longer alternative:
  // void (*pPrint)(int);
  // pPrint = &print; // or = print;
  // (*pPrint)(5);

  return 0;
}