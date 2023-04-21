#include <iostream>
#include <vector>
using namespace std;

class Test {

public:
	Test() {
		cout << "constructor" << endl;
	}

	Test(int i) {
		cout << "parameterized constructor" << endl;
	}

	Test(const Test &other) {
		cout << "copy constructor" << endl;
	}

	Test &operator=(const Test &other) {
		cout << "assignment" << endl;
		return *this;
	}

	~Test() {
		cout << "destructor" << endl;
	}

	friend ostream &operator<<(ostream &out, const Test &test);
};

ostream &operator<<(ostream &out, const Test &test) {
	out << "Hello from test";
	return out;
}

Test getTest() {
	// It is inefficient to return an object by value
	return Test();
}

int main() {

	// Inefficiencies can be found in C++98 without compiler optimization:
	// Without copy elision in C++98, the copy constructor and destructor runs twice
  Test test = getTest();

	cout << test << endl;

	vector<Test> vec;
	// When pushing an object to a vector, the object is created and then moved.
	// C++11 allows to optimize this procedure with move constructors
	vec.push_back(Test());

	return 0;
}