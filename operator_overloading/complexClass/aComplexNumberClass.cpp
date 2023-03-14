#include <iostream>
#include "Complex.h"

// If using two namespaces, there could be a conflict of functions that are called the same 
using namespace std;
using namespace udemy;

int main() {

	// Copy constructor, assignment and equality operator 
	Complex c1(2, 3);
	Complex c2(c1);
	Complex c3(3,2);

	Complex c4;
	c4 = c3;

	cout << c1 << " = " << c2 << endl;

	if (c4 == c3) {
		cout << c3 << " = " << c4 << endl;
	}
	if (c1 != c3) {
		cout << c1 << " != " << c3 << endl;
	}

	// Plus overloading
	c4 = c1+c3;
	cout << 1+c4+5 << endl;

	// * Overloading
	Complex c5 = *c1;
	cout << "Conjugate of " << c1 << " is " << c5 << endl;
	// The * operator can be used directly without using a variable
	cout << "Initialization of a conjugate: " << *Complex(1,1) << endl;

	return 0;
}
