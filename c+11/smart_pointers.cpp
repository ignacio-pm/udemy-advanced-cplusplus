#include <iostream>
#include <memory>

using namespace std;

class Test {
public:
	Test() {
		cout << "Constructor" << endl;
	}

	~Test() {
		cout << "Destructor" << endl;
	}

  void print() {
    cout << "Print from class" << endl;
  }
};

int main() {
  // Unique pointers owns a resource exclusively (it does not have other pointers). 
  // Therefore, these pointers cannot be copied (pCopy = pUnique) but they can be moved.
  // The memory allocation is destroyed after the pointer gets out of scope. 
  // auto_ptr is deprecated in C++11
  int number = 1;
  unique_ptr<int> pInt = make_unique<int>(number);
  // pInt cannot be used after being moved
  unique_ptr<int> newPointer = move(pInt);
  cout << *newPointer << endl;

  // Curly brackets can be used to reduce the scope of the variable inside them.
  // Therefore, the memory deallocation is done at the end of the brackets
  {
    // Alternative added in C++14 to pTest(new Test());
    unique_ptr<Test> pTest = make_unique<Test>();
    pTest->print();
  }

  cout << "-------" << endl;

  // shared_ptr can share ownership of a resource (it can have other pointers). 
  // It can be copied and moved. The allocation is destroyed when all the pointers get out of scope
  // The main applications of shared_ptr are parallel programming (multi-threads) and STL containers
  shared_ptr<Test> pCopy(nullptr);
  // The memory deallocation is done at the end of the program because that is the largest scope of
  // all the copies of the pointer.
  {
    shared_ptr<Test> pShared(new Test());
    pCopy = pShared;
  }

  auto pOther = pCopy;
  pCopy->print();

  cout << "End of program" << endl;

  return 0;
}