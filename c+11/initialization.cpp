#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class personalData {
  // To initialize a class with initializer list, the variables need to be public
  public: 
    string name;
    int age;
    int height;
    double weight;
    void print() const {
      cout << "Data: " << name << ", " << age << ", " << height << ", " << weight << endl;
    }
};

int main() {
  // List initialization in C++98
  personalData data = {"Peter", 18, 175, 86.4};
  data.print();

  // In C++11 the equal sign is not necessary for list initialization (brace-init-list)
  personalData otherData{"Jack", 27, 178, 70.6};
  string texts[]{"one", "two", "three", "four"};
  int *pNumbers = new int [] {1, 2, 3, 4, 5};
  cout << pNumbers[4] << endl;
  delete[] pNumbers;
  
  vector<double> vDoubles{1.0, 2.0, 3.0, 4.0};
  for (auto number: vDoubles) {
    cout << number << ", " << flush;
  }
  cout << endl;
  // Default list initialization. If brackets are empty, the default value of the type is chosen
  personalData emptyData[2]{};
  // The default value for type string is an empty string and 0 for type int or double
  emptyData[1].print();
  
  // The default value for a pointer is a nullptr (with memory address 0x0)
  int *pNumber{};
  cout << pNumber << endl;
  
  return 0;
}