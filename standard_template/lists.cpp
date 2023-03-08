#include <iostream>
#include <list>
using namespace std;

int main() {
  // Difference between vector and list is that items can be inserted in the beginning or the 
  // middle of the list. List items are connected with pointers, not with indexes.
  list<int> v_numbers;
  v_numbers.push_back(1);
  v_numbers.push_back(2);
  v_numbers.push_back(3);
  v_numbers.push_back(4);
  v_numbers.push_front(0);

  // Insert a number in the second position
  list<int>::iterator it = v_numbers.begin();
  it++;
  // The insert method returns the updated iterator that points to the new inserted item.
  it = v_numbers.insert(it, 100);
  cout << "Element: " << *it << endl;
  cout << "------" << endl;

  // Delete a number in the position that was inserted
  it = v_numbers.erase(it);
  // The returned iterator points to the next element of the list.s
  cout << "Element: " << *it << endl;
  cout << "------" << endl;

  // Delete the elements that contains number 2 and 3
  it = v_numbers.begin();
  while(it != v_numbers.end()) {
    if (*it == 2 || *it == 3) {
      it = v_numbers.erase(it);
    } else {
      it++;
    }
  }

  for(list<int>::iterator it = v_numbers.begin(); it != v_numbers.end(); it++) {
    cout << *it << endl;
  }
  cout << "------" << endl;

  return 0;
}