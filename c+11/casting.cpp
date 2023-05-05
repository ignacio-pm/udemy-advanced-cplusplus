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
  const float pi = 3.1416;
  cout << static_cast<int>(pi) << endl;
  // Alternative: 
  // cout << (int)pi << endl;
  
  // A parent object can be casted into child. It is dangerous because parent has different methods
  // and can be called incorrectly. This case is not check with static cast
  // Possible use: Create a pointer from a child to a parent and convert back to a child pointer

  Shape shape;
  Circle circle;
  Square square;

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

  // Reinterpret_cast checks less condition than static_cast. Therefore, it can be used, for 
  // example, casting between childs or low-level operations. However, it is not frequently used
  Square *p_square = reinterpret_cast<Square *>(p_circle);

  // Const_cast can convert a reference or a pointer from const to non-const.
  float variable_pi = const_cast<float &>(pi);
  variable_pi++;
  cout << variable_pi << endl;

  return 0;
}