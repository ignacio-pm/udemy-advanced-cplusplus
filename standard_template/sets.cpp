#include <iostream>
#include <set>
using namespace std;

int main() {
  // Set is a list of items that is automatically ordered and does not accept duplicates.
  set<string> names;
  names.insert("Mike");
  names.insert("Adrian");
  names.insert("Adrian");
  names.insert("James");
  names.insert("Jack");

  // Loop through the set and print its values
  for(set<string>::iterator it = names.begin(); it != names.end(); it++) {
    cout << *it << endl; 
  }
  cout << "-------" << endl;

  // Find a value and output it with an iterator
  set<string>::iterator itFind = names.find("Adrian");
  if(itFind != names.end()) {
    cout << *itFind << endl;
  }
  
  // Check if a value is contained in the set
  string name = "Jack";
  if(names.count(name)) {
    cout << "Found " << name << endl;
  }

  return 0;
}