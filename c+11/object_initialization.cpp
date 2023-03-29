#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// Global variable that saves the last id used
int lastId = 1;

class personalData {
  private: 
    // Default value for a variable can be given from C++11. Constructor can override it
    int id{lastId++};
    int age{0};
    int height = 50;
    double weight = 3.3;
  public:
    // Default constructor. This constructor is needed because it is implicitly deleted
    personalData() = default;
    // Constructor with default id
    personalData(int age, int height, double weight) : age(age), height(height), weight(weight) { }
    // Constructor with custom id
    personalData(int id, int age, int height, double weight) : 
                  id(id), age(age), height(height), weight(weight) { }
    // Custom copy constructor. Id is not copied but the variable lastId is used to avoid duplicates
    personalData(personalData &other) : 
                  id(lastId++), age(other.age), height(other.height), weight(other.weight) { }

    // Default equals operator. This operator is not needed since it is implicitly created
    personalData &operator=(const personalData &other) = default;

    // If the objects should be non-copyable, the copy constructor and the = operator can be deleted
    // personalData(personalData &other) = delete;
    // personalData &operator=(const personalData &other) = delete;

    // Print method that outputs the variables of the class in the terminal
    void print() const {
      cout << "Data: " << id << ", " << age << ", " << height << ", " << weight << endl;
    }
};

int main() {
  // Initialization with custom id
  personalData data(99, 18, 175, 86.4);
  cout << "Someone's data: " << endl;
  data.print();

  // Default list initialization still works but default values are taken from the class
  // personalData data{} is equals to personalData data, if all class variables have default values
  personalData emptyData{};
  cout << "C++ default data: " << endl;
  emptyData.print();

  // Only used this initialization if all variables have default values
  // If not, random values are given. Example: Data: -1094233088, 32759, 208838787, 2.19075e-314
  personalData defaultData;
  cout << "Custom default data: " << endl;
  defaultData.print();

  defaultData = data;
  cout << "Default equal sign (same id as copied object) data: " << endl;
  defaultData.print();

  personalData copyConstructorData = data;
  cout << "Custom copy constructor (with new id) data: " << endl;
  copyConstructorData.print();
  
  return 0;
}