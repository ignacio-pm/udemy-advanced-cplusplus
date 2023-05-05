#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

class IntsPointer {
private:
	static const int SIZE = 100;

	// Initialize pointer to null
  int *_pBuffer { nullptr };

public:

	// Constructor that calls a zero initialization of the pointer 
	IntsPointer() {
		_pBuffer = new int[SIZE] { };
	}

	// Constructor that initializes the pointer with incremental values
	IntsPointer(int i) {
		_pBuffer = new int[SIZE] { };

		for (int i = 0; i < SIZE; i++) {
			_pBuffer[i] = i;
		}
	}

	// Copy constructor
	IntsPointer(const IntsPointer &other) {
		// Pointer needs to be initialized since the constructor was still not run. C++11 alternative:
		// IntsPointer(const IntsPointer &other) :  IntsPointer()
		_pBuffer = new int[SIZE] { };
		// Copy the memory block from the pointer of other object to this
		memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
	}

	// Move constructor. Similar than copy constructor but for a RValue object
  IntsPointer(IntsPointer &&other) {
		cout << "Move constructor" << endl;

		_pBuffer = other._pBuffer;
		// Set the previous object pointer to nullptr so the buffer is not deallocated which would 
		// affect the new object
		other._pBuffer = nullptr;
	}

	// Assignment operator
	IntsPointer &operator=(const IntsPointer &other) {
		_pBuffer = new int[SIZE] { };

		memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
		return *this;
	}

	// Move assignment operator. Assign an RValue object to a initialized object 
	IntsPointer &operator=(IntsPointer &&other) {
		cout << "Move assignment" << endl;

		// Delete pointer stored in the initialized object before the assignment
		delete [] _pBuffer;
		// Assign the pointer of the RValue to the object
		_pBuffer = other._pBuffer;
		// Set the pointer of the RValue to null (RValue object will be directly deleted)
		other._pBuffer = nullptr;
		return *this;
	}

	// Destructor. Deletes pointer
	~IntsPointer() {
		delete[] _pBuffer;
	}

	friend ostream &operator<<(ostream &out, const IntsPointer &obj);
};

ostream &operator<<(ostream &out, const IntsPointer &obj) {
	for (int i = 0; i < obj.SIZE; i++) {
		out << obj._pBuffer[i] << " ";
	}
	return out;
}

// Gets a IntsPointer object
IntsPointer getPointer() {
	return IntsPointer();
}

int main() {
	vector<IntsPointer> vec_pointers;
	vec_pointers.push_back(IntsPointer(1));
	cout << vec_pointers[0] << endl;

	IntsPointer pointer;
	// To call the move assignment operator, a RValue object is assigned to a declared variable 
	pointer = getPointer();

	return 0;
}