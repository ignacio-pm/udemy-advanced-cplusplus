#include <iostream>
#include <fstream>
using namespace std;

struct Person {
  char name[50];
  int age;
  double height;
};

int main() {

  Person someone = {"Frodo", 220, 0.8};
  string filePath = "binary.bin";
  
  // 1. Write to file
  // Output stream file (allows only writing)
  ofstream outFile;
  // If file is fstream (read/write) then: .open(filePath, ios::binary | ios::out)
  outFile.open(filePath, ios::binary);

  if(outFile.is_open()) {
    // Size of the object to be written is necessary
    outFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));
    // Alternative of reinterpret_cast<char *>: (char *)(&someone)
    outFile.close();
  } else {
    cout << "Error while opening file" << filePath << endl;
  }
  
  // 2. Read from file
  Person someoneElse = {};
  ifstream inFile;

  inFile.open(filePath, ios::binary);

  if(inFile.is_open()) {
    inFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));
    inFile.close();
  } else {
    cout << "Error while opening file." << filePath << endl;
  }

  // Check read data saved in the variable someoneElse
  cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.height << endl;
  return 0;
}