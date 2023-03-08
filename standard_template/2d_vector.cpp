#include <iostream>
#include <vector>
using namespace std;

int main() {
  // Create 2D vector of 10x12 with initial values = 0
  vector < vector<int> > table12(10, vector<int>(12, 0));

  // Fill up the vector with the indexes
  for (int row = 0; row < table12.size(); row++) {
    for(int col = 0; col < table12[row].size(); col++) {
      table12[row][col] = (row + 1) * (col + 1);
    }
  }

  // Print in order to check if table is correct
  for (int row = 0; row < table12.size(); row++) {
    for(int col = 0; col < table12[row].size(); col++) {
      cout << table12[row][col] << flush;
    }
    cout << endl;
  }
  return 0;
}