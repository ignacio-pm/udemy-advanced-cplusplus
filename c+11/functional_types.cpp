#include <iostream>
// Used for the standard function type
#include <functional>
#include <vector>
// Used for count_if
#include <algorithm>
using namespace std;

// Function to check if the argument value is odd
bool checkOdd (int value) {
  return (value % 2) == 1;
}

// Function that accepts a function and a number that will be given to the object as argument.
// The callable object, which is denoted by the template type function can be a lambda expression, 
// function pointer or a functor.
void printFunctionResult(function<bool(int&)> funct, int &number) {
  cout << boolalpha << funct(number) << endl;
}

// Class that has a multiple variable which is used to calculate the multiplicity of a value
class CheckMultiple {
  int multiple;
public:
  CheckMultiple(int multiple) : multiple(multiple) { }
  // Operator overloading to allow class to calculate the multiplicity of a value as a functor
  bool operator()(int value) {
    return (value % multiple) == 0;
  }
} checkMult3(3); // Object can be initialized after the declaration of the class

int main() {
  int multiple = 2;
  vector<int> numbers{1, 3, 5, 7, 9, 8, 6, 4, 2};
  auto checkMultipleLambda = [multiple](int value) {
    return (value % multiple) == 0;
  };
  
  // Use the count_if function from algorithm library with function pointer, functor and lambda exp
  // count_if's that the input function pointer returns bool with input type of the vector
  
  // Lambda expresion
  int countMult = count_if(numbers.begin(), numbers.end(), checkMultipleLambda);
  // Function pointer
  int countOdds = count_if(numbers.begin(), numbers.end(), checkOdd);
  // Functor
  int countMult3 = count_if(numbers.begin(), numbers.end(), checkMult3);

  cout << "There are " << countMult << " multiples of " << multiple << endl;
  cout << "There are " << countOdds << " odd numbers" << endl;
  cout << "There are " << countMult3 << " multiples of 3" << endl;

  int value = 6;
  // Print if the value is multiple of the values stored on the callable objects
  cout << "Multiple of " << multiple << ": "<< flush;
  printFunctionResult(checkMultipleLambda, value);
  cout << "Odd: " << flush;
  printFunctionResult(checkOdd, value);
  cout << "Multiple of 3: " << flush;
  printFunctionResult(checkMult3, value);

  return 0;
}