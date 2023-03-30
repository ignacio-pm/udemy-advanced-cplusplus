#include <iostream>
#include <functional>
using namespace std;

void print(void (*pFunction)() ) {
  pFunction();
}

void greetJack(void (*pGreet)(string) ) {
  pGreet("Jack");
}

// Class to show capturing this in lambda expressions
class personalData {
  private:
    int id{0};
    int age{0};
    int height = 50;
    double weight = 3.3;
  public:
    personalData() = default;
    personalData(int id, int age, int height, double weight) : 
                  id(id), age(age), height(height), weight(weight) { }

    void print(string name) const {
      // Passing this to a lambda expression allows to use the class variables.
      // this cannot be used with default value initialization [=, this] (until C++20)
      auto pLambda = [&, this]() {
        cout << "Data from " << name << " : " << id << ", " << age << ", " << height << ", " << weight << endl;
      };
      pLambda();
    }
};

int main() {
  // Lambda expresion allows to pass code to functions to be executed inside.
  // C++ can usually infer the return type of the lambda expression.
  // Every instance of a lambda introduces a new type.
  // In the case of a non-capturing lambda ([]), the structure has an implicit conversion 
  // to a function pointer. However, in these cases is still recommended to use auto

  // Extra information: How to specify the type of a non-capturing lambda expression
  // As a function: function<return_type(input_type1, input_type2)>
  // Problem: Less efficient and it can not be passed to a function that expects a function pointer.
  // As a function pointer: return_type(*variable_name)(input_type1, input_type2).
  // Is only compatible with functions that expect a standard function and not a function pointer

  auto printFunction = [](){ cout << "Hello World" << endl; };

  // The lambda expression can be passed to a function and be executed there (only non-capturing)
  print(printFunction);

  // Lambda expression can be passed directly without initializing a variable
  greetJack([](string name) { cout << "Hello " << name << endl; });

  // Trailing return type is used when two arguments of different type are returned, 
  // since C++ cannot infer the return type. Another possible use is to force a concrete return type
  function<double(double,double)> divideFunction = [] (double a, double b) -> double {
    if(b == 0) {
      return 0;
    } else {
      return a/b;
    }
  };

  cout << divideFunction(4.0,3.0) << endl;
  cout << "------" << endl;

  int number1 = 1;
  int number2 = 2;
  int number3 = 3;

  // Square braces are used to capture local variables to use them in the lambda expresion.
  // Possible to capture by value or reference
  
  // Capture number1 by value and number2 by reference (needs to be declared but can be modified)
  [number1, &number2, number4 = 4]() {
    number2 = 22; 
    cout << number1 << ", " << number2 << ", " << number4 << endl;
  }(); // Parenthesis execute the lambda expression directly

  // Pass all local variables by value except number1 that will be passed as reference
  [=, &number1]() {
    number1 = 11; 
    cout << number1 << ", " << number2 << ", " << number3 << endl;
  }();

  // Pass all local variables by reference
  [&]() {
    number3 = 33; 
    cout << number1 << ", " << number2 << ", " << number3 << endl;
  }();

  cout << "------" << endl;

  personalData sophieData{1, 20, 170, 75.4};
  // print method calls a lambda function that uses the class private variables by capturing this
  sophieData.print("Sophie");

  return 0;
}