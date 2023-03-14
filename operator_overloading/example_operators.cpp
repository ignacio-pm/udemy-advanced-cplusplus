#include <iostream>
#include <memory>
using namespace std;

// Program to show smart pointers in a class with custom constructors and operators.

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
    unique_ptr<double[]> pData;
  public:
    // Extra constructor that fills only name and id. Scores are not given a value.
    examScores(string name) : name(name), pData(new double[numberExams]) {
      cout << "Name constructor" << endl;
      last_id += 1;
      id = last_id;
    }

    // Default constructor with a name and an array or a pointer to the scores
    examScores(string name, double *inputPData) : name(name), pData(new double[numberExams]) {
      cout << "Complete constructor" << endl;
      last_id += 1;
      id = last_id;
      // Create a heap pointer that contains the values of the input arrays
      // pData = new double[numberExams];
      copy(&inputPData[0], &inputPData[0]+numberExams, &pData[0]);
    }

    // Copy constructor that assigns new id and maintains the name and the scores with a new pointer
    examScores(const examScores &other) : name(other.name), pData(new double[numberExams]) {
      cout << "Copy constructor" << endl;
      last_id += 1;
      id = last_id;
      // Copy the scores from pointer to pointer.
      copy(&other.pData[0], &other.pData[0]+numberExams, &pData[0]);
    }
    // Custom destructor is not necessary because memory from pointers is managed by compiler

    // Overwrite the assignment operator to assign last id and copy the results
    examScores &operator=(const examScores &other) {
      // If not self-assignment
      if (this != &other) {
        cout << "Assignment operator" << endl;
        // With assignment, no new object is created so the last_id is not increased
        id = last_id;
        // The new initialization of the pointer is not necessary due to that no new object
        // is created and therefore, we can use the previous pointer.
        // pData = make_unique<double []>(numberExams);
        copy(&other.pData[0], &other.pData[0]+numberExams, &pData[0]);

      }
      return *this;
    }

    // Overwrite the left bit shift operator to print the object information directly with cout
    friend ostream &operator<<(ostream &out, const examScores &scores) {
      out << "Address: " << &(scores.pData[0]) << " -> "<< flush;
      out << scores.id << ": " << scores.name << ", " << flush;
      for(int i=0; i < numberExams; i++) {
        if(i < numberExams - 1) {
          out << scores.pData[i] << ", " << flush;
        } else {
          out << scores.pData[i] << " " << flush;
        }
      }
      return out;
    }

    // Print all the data of the examScores object
    void print() {
      cout << "Address: " << &pData[0] << endl;
      cout << id << ": " << name << ", " << flush;
      for(int i=0; i < numberExams; i++) {
        cout << pData[i] << ", " << flush;
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

  // Print with the print method
  first.print();
  second.print();
  copyFirst.print();
  copiedSecond.print();

  // Print using the left bit shift operator
  cout << first << second << endl;
  return 0;
}