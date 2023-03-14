#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
// Not good practice to using namespace in a header
// using namespace std;

namespace udemy {

class Complex {
private:
	double real;
	double imaginary;

public:
	Complex();
	Complex(double real, double imaginary);
	Complex(const Complex &other);
	const Complex &operator=(const Complex &other);

	// Gets the real component of the complex number
	// Const is necessary since the method is called from an const object in the << operator
	double getReal() const {
		return real;
	}
	// Gets the imaginary component of the complex number
	double getImaginary() const {
		return imaginary;
	}

	// Returns true if the real and imaginary numbers are the same
	bool operator==(const Complex &other) const;
	// Returns false if the real and imaginary numbers are the same
	bool operator!=(const Complex &other) const;
	// Returns the conjugate of the complex number with the star operator
	Complex operator*() const;
	
};

// Overload operator as non members allow to convert parameters on the left-hand of the operator:
// cout << Complex or double + Complex 

std::ostream &operator<<(std::ostream &out, const Complex &c);
Complex operator+(const Complex &c1, const Complex &c2);
Complex operator+(const Complex &c, double d);
// Two plus operators are needed in order to cover both positioning of the arguments
Complex operator+(double d, const Complex &c);


} /* namespace udemy */

#endif /* COMPLEX_H_ */
