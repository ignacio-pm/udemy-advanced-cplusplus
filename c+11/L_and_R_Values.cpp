#include <iostream>
#include <vector>
using namespace std;

class Test {
};

Test getTest() {
	return Test();
}

// Crete overloaded function with Lvalue and Rvalue references
void checkValueRef(const Test &ref) {
	cout << "This reference is a Lvalue reference" << endl;
}

// In C++11, R values references are added with a special notation (&&)
void checkValueRef(Test &&ref) {
	cout << "This reference is a Rvalue reference" << endl;
}

int main() {

  Test test = getTest();

	// L values (left value) are objects that can be addressed
	Test *pTest = &test;
	// R values are objects that cannot be addressed (due to being temporary), e.g. return values
	// Test *pTest2 = &getTest();

	int value = 1;
	// Same happens with references. The result of the prefix operator is a Lvalue
	int &rValuePrefix = ++value;
	cout << rValuePrefix << endl;
	value = 5;
	// The reference's value changes if the referenced object changes
	cout << rValuePrefix << endl;
	// The result of the postfix operator is a Rvalue and cannot be referenced the same way
	// int &rValue2 = value++;

	// R values can be referenced as const. The referenced object is LValue since it can be addressed 
  // Therefore, it can be fetched to a copy constructor
	const Test &rTestConst = getTest();
	Test newTest(rTestConst);
	cout << "-------" << endl;


  // A RValue can also be directly referenced with C++11 and the operator &&
	Test &&rTest11 = getTest(); // or Test();

	// The function returns Lvalue reference because the argument is an saved object
  checkValueRef(test);
  // The function returns a Rvalue reference
	checkValueRef(Test());
  // Now, it returns a Lvalue because is an object with address despite being a Rvalue reference
  checkValueRef(rTest11);

	return 0;
}