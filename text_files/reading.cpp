#include <iostream>
#include <fstream>
using namespace std;

int main() {

  ifstream inFile;

  string filePath = "file.txt";
  inFile.open(filePath);

  if(inFile.is_open()) {
    string line;
    // While loop until file is finished.
    while(inFile) {
      getline(inFile, line);
      cout << line << endl;
    }
    inFile.close();
  } else {
    cout << "Error while opening file." << endl;
  }

  return 0;
}