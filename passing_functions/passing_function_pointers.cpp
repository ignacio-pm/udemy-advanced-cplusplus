#include <iostream>
#include <vector>
using namespace std;

// Returns if the given string has the size given as argument
bool matchSize(const string &s, const int &size) {
  return s.size() == size;
}

// Returns if the given string has a size of 3
bool match3(const string &s) {
  return s.size() == 3;
}

// Return the count of the strings in a vector that fullfil the passing function
// Own version of count_if limited to vector of strings and a size argument
int countStringsWithSize(const vector<string> &strings, const int &size, 
                         bool (*pMatchSize)(const string &, const int &)) {
  int count = 0;
  // Const iterator is needed since the strings vector is passed as a const reference
  for(vector<string>::const_iterator it = strings.begin(); it != strings.end(); it++) {
    if (pMatchSize(*it, size)) {
      count ++;
    }
    // One-liner alternative but less readable
    // count += pMatchSize(*it, size);
  }
  return count;
}

// Sample code from count_if:
// count_if(_InputIterator __first, _InputIterator __last, _Predicate __pred)
// {
//   typename iterator_traits<_InputIterator>::difference_type __r(0);
//   for (; __first != __last; ++__first)
//     if (__pred(*__first))
//       ++__r;
//   return __r;
// }

int main() {
  // Size can be changed with giving the number to replace alls
  const int expected_size = 3;
  vector<string> strings;
	strings.push_back("one");
	strings.push_back("two");
	strings.push_back("three");
	strings.push_back("two");
	strings.push_back("four");
	strings.push_back("two");
	strings.push_back("three");

  cout << "Result from countStringsWithSize: " << flush;
  cout << countStringsWithSize(strings, expected_size, matchSize) << endl;
  cout << "Result from count_if: " << flush;
  cout << count_if(strings.begin(), strings.end(), match3) << endl;

  return 0;
}