#include <iostream>
using namespace std;

// Class Number that allows int, float and double.
template <class T>
class Number {
  T number;
  public:
    Number(T number) : number(number) {}
    T add(T other) {
      return number + other;
    }
    T minus(T other) {
      return number - other;
    }
    // Overload left bit operator to print the number variable of the class
    friend ostream &operator<<(ostream &out, Number &n) {
      out << n.number << flush;
      return out;
    }
};

int main() {
  Number<int> i(10);
  Number<double> d(23.9);
  Number<string> s("Hello");

  int sum = i.add(6);
  double minus = d.minus(3.3);
  // Strings can be used to be added but not to be subtracted
  string helloWorld = s.add(" World");

  cout << "Sum: " << sum << endl;
  cout << "Minus: " << minus << endl;
  cout << "Hello world: " << helloWorld << endl;

  return 0;
}