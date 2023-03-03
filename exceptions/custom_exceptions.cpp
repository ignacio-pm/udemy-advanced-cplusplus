#include <iostream>
using namespace std;

// Custom exception that inherits the members of std::exception
class HypeException : public exception {
  public:  
    // Method that describes the exception with an array of chars.
    virtual const char* what() {
      return "Too much hype";
    }
};

void TooMuchHype() {
  throw HypeException();
}

int main() {
  try {
    TooMuchHype();
  } catch (HypeException & e){
    cout << "Caught Exception: " << e.what() << endl;
  }
  return 0;
}