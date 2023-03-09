#include <iostream>
using namespace std;

// Program to show heap pointers in a class with custom constructors and operators.

// Global variables to determine the length of the score arrays and count the ids of the objects.
const int numberExams = 5;
int last_id = 0;

class examScores {
  private:
    // Name of the student
    string name;
    // Unique id
    int id;
    // Pointer to the exam scores of size numberExams
    double *pData;
  public:
    // Constructor that fills only name and id (Null pointer).
    examScores(string name) : name(name) {
      cout << "Name constructor" << endl;
      last_id += 1;
      id = last_id;
      pData = nullptr;
    }
    // Complete constructor
    examScores(string name, double *aData) : name(name) {
      cout << "Complete constructor" << endl;
      last_id += 1;
      id = last_id;
      // Create a heap pointer that contains the values of the input arrays
      pData = new double[numberExams];
      copy(aData, aData+numberExams, pData);
    }
    // Destructor to delete the pointer from heap
    ~examScores() {
      cout << "Destructor" << endl;
      // This will cause an error if pointer is not stored in heap.
      delete[] pData;
    }

    // Copy constructor
    examScores(const examScores &other) {
      cout << "Copy constructor" << endl;
      name = other.name;
      last_id += 1;
      id = last_id;
      pData = new double[numberExams];
      // Copy the scores from pointer to pointer.
      copy(other.pData, other.pData+numberExams, pData);
    }

    // Assign last id and copy the results
    examScores &operator=(const examScores &other) {
      // If not self-assignment
      if (this != &other) {
        cout << "Assignment operator" << endl;
        // With assignment, no new object is create so the last_id is not increased.
        id = last_id;
        pData = new double[numberExams];
        // copyInPointer(other.pData, pData);
        copy(other.pData, other.pData+numberExams, pData);
      }
      return *this;
    }

    // Print all the data of the examScores object
    void print() {
      cout << "Address: " << pData << endl;
      cout << id << ": " << name << ", " << flush;
      for(int i=0; i < numberExams; i++) {
        cout << *(pData+i) << ", " << flush;
      }
      cout << endl;
    }
};

int main() {
  // Initialize array
  double firstScores[numberExams] = {4.4, 6.5, 7.3, 4.7, 7.6};
  double secondScores[numberExams] = {6.5, 8.5, 8.9, 6.2, 5.3};

  // Initialize scores for two students
  examScores first("Mike", firstScores);
  examScores second("Jack", secondScores);

  // copyFirst is a copy of the first student
  examScores copyFirst = first;
  // Jamie copied all the exams from Jack and has the same scores
  examScores copiedSecond("Jamie");
  copiedSecond = second;

  // Print the different student's information
  first.print();
  second.print();
  copyFirst.print();
  copiedSecond.print();
  return 0;
}