#include <iostream>
#include <fstream>
using namespace std;

int main() {

  // ofstream outFile;
  fstream outFile;

  string filePath = "file.txt";
  // If ofstream, ios::out is not necessary.
  outFile.open(filePath, ios::out);

  if(outFile.is_open()) {
    for(unsigned int i = 0; i < 10; i++) {
      outFile << "This is the line " << i+1 << " of the file" << endl;
    }
    outFile.close();
  } else {
    cout << "Error while opening file." << endl;
  }

  return 0;
}