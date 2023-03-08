#include <iostream>
#include <map>
using namespace std;

int main() {
  // Multimaps allows to store multiple items with the same key. A map of vectors is an alternative.
  multimap<string, int> mmap;
  mmap.insert(make_pair("Mike", 30));
  mmap.insert(make_pair("Fernando", 40));
  mmap.insert(make_pair("Adrian", 50));
  mmap.insert(make_pair("Adrian", 60));
  mmap.insert(make_pair("Mike", 50));

  // Loop through the multimap has the same structure as normal maps
  for (multimap<string, int>::iterator it = mmap.begin(); it != mmap.end(); it++) {
    cout << it->first << ": " << it->second << endl;
  }
  cout << "----------" << endl;

  // Since there can be multiple items with a key, a range of items is needed to find these values.
  pair<multimap<string, int>::iterator, multimap<string, int>::iterator> its = mmap.equal_range("Adrian");
  // In C++11 the keyword auto can be used to simplified the iterators initialization.
  auto its = mmap.equal_range("Mike");

  for (multimap<string, int>:: iterator it=its.first; it != its.second; it++) {
    cout << it->first << ": " << it->second << endl;
  }

  return 0;
}