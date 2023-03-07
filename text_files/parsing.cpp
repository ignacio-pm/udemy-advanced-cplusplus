#include <iostream>
#include <fstream>
using namespace std;

int main() {

  ifstream inFile;

  string filePath = "stats.txt";
  inFile.open(filePath);

  if(!inFile.is_open()) {
    return 1;
  }
  while(inFile) {
    string line;
    // Insert the read items in the line until the character : is found. Character is deleted.
    getline(inFile, line, ':');
    
    int population;
    inFile >> population;

    // inFile.get();
    // Extracts the white spaces
    inFile >> ws;

    if(!inFile) {
      break;
    }

    cout << "'" << line << "'" << " -- " << "'" << population << "'" << endl;
  }
  inFile.close();

  return 0;
}