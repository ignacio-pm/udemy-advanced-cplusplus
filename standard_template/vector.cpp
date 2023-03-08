#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<string> v_strings;
  v_strings.push_back("good");
  v_strings.push_back("better");
  v_strings.push_back("best");

  // Loop through vector with size
  for(int i = 0; i < v_strings.size(); i++) {
    cout << i << ": " << v_strings[i] << endl;
  }

  cout << "------" << endl;

  // Loop through vector with iterator
  for (vector<string>::iterator it = v_strings.begin(); it != v_strings.end(); it++) {
    cout << *it << endl;
  }

  cout << "------" << endl;

  // Loop through reversed vector with iterator
  for (vector<string>::reverse_iterator it = v_strings.rbegin(); it != v_strings.rend(); it++) {
    cout << *it << endl;
  }

  cout << "------" << endl;

  // Loop through vector from C++11
  for (string string : v_strings) {
    cout << string << endl;
  }

  return 0;

}