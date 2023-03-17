#include <iostream>
using namespace std;

// Abstract classes are classes with one or more pure virtual functions. They cannot be instantiated
class Shape {
  public:
    // Pure virtual methods force child classes to override the method
    virtual double getArea() const = 0;
};

class Square : public Shape {
  private:
    double length;
  public: 
    Square(double length) : length(length) {}
    virtual double getArea() const {
      return length*length;
    }
};
class Circle : public Shape {
  private:
    double radius;
  public: 
    Circle(double radius) : radius(radius) {}
    virtual double getArea() const {
      return 3.1416*radius*radius;
    }
};

// Function that prints the result of the method getArea() of a child of Shape
void printArea(const Shape &s) {
  cout << s.getArea() << endl;
}

int main() {
  Square square(5.5);
  Circle circle(5.0);
  // Initializing the class throws an error:
  // Shape shape();
  // But a reference of an abstract class to a non-abstract child is allowed
  Shape &squaredShape = square;
  // The methods used by this reference are the ones of the child class
  cout << squaredShape.getArea() << endl;
  // An array of pointers can be created that points to different child classes
  Shape *shapes[3];
  shapes[0] = &square;
  shapes[1] = &circle;
  cout << shapes[1]->getArea() << endl;

  // Due to polymorphism, any child can be passed to a function that expects the parent
  printArea(square);
  return 0;
}