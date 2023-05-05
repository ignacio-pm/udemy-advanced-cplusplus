#include <iostream>
using namespace std;

class Shape {
public:
  // For the dynamic casting a virtual method is necessary
  virtual ~Shape() {
  }
};

class Circle : public Shape {
};

class Square : public Shape {
};

int main() {
  // Static cast
  // Simple use: Cast a float into int
  float pi = 3.1416;
  cout << static_cast<int>(pi) << endl;
  // Alternative: 
  // cout << (int)pi << endl;
  
  // A parent object can be casted into child. It is dangerous because parent has different methods
  // and can be called incorrectly. This case is not check with static cast
  // Possible use: Create a pointer from a child to a parent and convert back to a child pointer

  Shape shape;
  Circle circle;

  // It is possible to automatically cast a child into parent but not vice versa
  Shape *p_shape = &circle;
  Circle *p_circle = static_cast<Circle *>(p_shape);

  // For this, it is better to use dynamic_cast, which checks at runtime the validity of the cast.
  // It will return a nullptr if the cast is not successful.
  Circle *p_dynamic = dynamic_cast<Circle *>(p_shape);

  // If line 37 is = &circle then pointer is valid but if instead = &shape then pointer is null
  if(p_dynamic == nullptr) {
    cout << "Invalid pointer" << endl;
  } else {
    cout << p_dynamic << endl;
  }

  return 0;
}