#include <iostream>
using namespace std;

class Shape {
  // If variable are protected, they are available in the child classes
  private:
    double area;

  public:
    // A default constructor is needed for the initialization of the child class.
    // Remember: Default constructor is not declared because another constructor exists
    Shape () {}
    // C++11 alternative:
    // Shape () = default;
    Shape (double area) : area(area) {}
    Shape (const Shape & other) {}
    // Virtual allows child classes to override the method
    virtual double getArea() {
      return area;
    }
};

class Square : public Shape {
  private:
    double length;
  public: 
    Square(double length) : length(length) {
      // area = length*length; Area is inaccessible due to being private in the parent class
    }
    virtual double getArea() {
      return length*length;
    }

};
int main() {
  Square square(5.5);
  // Reference of a parent type that points to a child variable 
  Shape &squaredShape = square;

  // getArea of the shape returns an uninitialized variable if the method of shape is not virtual
  cout << squaredShape.getArea() << endl;
  // Use copy constructor of Shape from a child object. However, the components of Square
  // are not present in the new object because they are not part of the class Shape.
  // This is called object slicing (overcasting a child object to the parent type)
  Shape newShape = Square(6.0);
  // getArea of the shape returns an uninitialized variable due to the object slicing
  cout << newShape.getArea() << endl;
  return 0;
}