#include <iostream>
#include "ring.h"

using namespace std;

int main() {
  ring<string> string_ring(3);
  string_ring.add("cow");
  string_ring.add("cat");
  string_ring.add("dog");
  string_ring.add("rabbit");

  // The copy constructor of ring is used to copy the values and the actual position of string_ring
  ring<string> new_ring = string_ring;
  new_ring.add("penguin");

  // It is desired to loop through the ring similar to a vector. Therefore an iterator class needs
  // to be implemented
  for (ring<string>::iterator it = string_ring.begin(); it != string_ring.end(); it++) {
    cout << *it << endl;
  }

  // If an iterator loop runs, a range based loop in C++11 runs without extra implementation
  for (string str: new_ring) {
    cout << str << endl;
  }

  return 0;
}