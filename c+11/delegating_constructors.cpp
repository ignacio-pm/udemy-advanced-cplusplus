#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// A similar concept was already in C++98. A child class calls a specific constructor of the parent
// by using the same notation as the delegating constructor: Child() : Parent(input_parent) { } 

// Global variable that saves the last id used
int lastId = 1;

// Class used in object_initialization with delegating constructors
class personalData {
  private: 
    int id{lastId++};
    int age{0};
    int height = 50;
    double weight = 3.3;
  public:
    // Default constructor
    personalData() = default;
    // Constructor with default id
    personalData(int age, int height, double weight) : age(age), height(height), weight(weight) { 
      cout << "Copy constructor with default id" << endl;
    }
    // Constructor with custom id. It calls the constructor with default id and then updates the id. 
    // Delegating constructor does not allow other variables to be mem-initialized (parenthesis)
    // Therefore, the id has to be updated inside the constructor (after the delegating constructor)
    personalData(int id, int age, int height, double weight) : personalData(age, height, weight) {
      cout << "Copy constructor with custom id" << endl;
      // If the variable of the class has the same name as the input, the keyword this is necessary
      this->id = id;
    }
    // Print method that outputs the variables of the class in the terminal
    void print() const {
      cout << "Data: " << id << ", " << age << ", " << height << ", " << weight << endl;
    }
};

int main() {
  // Initialization with custom id calls both default id constructor and custom id constructor
  personalData data(99, 18, 175, 86.4);
  cout << "Someone's data: " << endl;
  data.print();
  
  return 0;
}