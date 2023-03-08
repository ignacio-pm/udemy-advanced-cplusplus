#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v_ints;

  // Capacity is the size of internal vector of the array, which is stored
  // in the memory. Therefore, capacity represents memory consumption.
  int capacity = v_ints.capacity();
  for(int i = 0; i < 10000; i++) {
    v_ints.push_back(i);
    if (capacity != v_ints.capacity()) {
      capacity = v_ints.capacity();
      cout << i << ": " << v_ints[i] << endl;
      cout << "New capacity: " << capacity << endl;
    }
  }
  cout << "------" << endl;

  // Careful because indixes > size < capacity can be falsy accessed!!
  cout << "Size: " << v_ints.size() << endl;
  cout << "Index 16300: " << v_ints[16300] << endl;
  cout << "------" << endl;

  // Sets size to 0 but not the capacity or the object values
  v_ints.clear();
  cout << "Size: " << v_ints.size() << endl;
  cout << "Capacity: " << v_ints.capacity() << endl;
  cout << "Index 100: " << v_ints[100] << endl;
  cout << "------" << endl;

  // Sets size to the input number but not the capacity or the object values
  v_ints.resize(10);
  cout << "Size: " << v_ints.size() << endl;
  cout << "Capacity: " << v_ints.capacity() << endl;
  cout << "Index 100: " << v_ints[100] << endl;
  cout << "------" << endl;

  // Increase capacity to the input number 
  v_ints.reserve(100000);
  cout << "Size: " << v_ints.size() << endl;
  cout << "Capacity: " << v_ints.capacity() << endl;
  cout << "Index 100: " << v_ints[100] << endl;
  cout << "------" << endl;

  return 0;

}