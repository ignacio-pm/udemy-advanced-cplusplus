#include "Complex.h"

namespace udemy {

Complex::Complex(): real(0), imaginary(0) { }

Complex::Complex(double real, double imaginary): real(real), imaginary(imaginary) { }

// The copy constructor and the assignment operator
Complex::Complex(const Complex &other) {
	real = other.real;
	imaginary = other.imaginary;
}

const Complex &Complex::operator=(const Complex &other) {
	real = other.real;
	imaginary = other.imaginary;

	return *this;
}

std::ostream &operator<<(std::ostream &out, const Complex &c) {
	out << "(" << c.getReal() << "," << c.getImaginary() << ")";
	return out;
}

Complex operator+(const Complex &c1, const Complex &c2) {
	return Complex(c1.getReal() + c2.getReal(), c1.getImaginary() + c2.getImaginary());
}

Complex operator+(const Complex &c, double d) {
	return Complex(c.getReal()+ d, c.getImaginary());
}

Complex operator+(double d, const Complex &c) {
	return Complex(c.getReal()+ d, c.getImaginary());
}
bool Complex::operator==(const Complex &other) const {
	return (real == other.real) && (imaginary == other.imaginary);
}
bool Complex::operator!=(const Complex &other) const {
	return !(*this==other);
}
Complex Complex::operator*() const {
		return Complex(real, -imaginary);
}

} /* namespace udemy */
