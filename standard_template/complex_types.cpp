#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
  map <string, vector<double> > examScores;
  examScores["Mike"].push_back(9.5);
  examScores["Adrian"].push_back(4.5);
  examScores["Vicky"].push_back(7.0);
  examScores["Adrian"].push_back(6.5);
  examScores["Vicky"].push_back(3.0);
  examScores["Mike"].push_back(8.5);
  examScores["Vicky"].push_back(6.0);

  // C++11 code. Type of iterator is map <string, vector<double> >::iterator
  for(auto it = examScores.begin(); it != examScores.end(); it++) {
    cout << "Name: " << it->first << "; Scores: " << flush;
    // vector<double> scores = it->second;
    for(auto score : it->second) {
      cout << score << " " << flush;
    }
    cout << endl;
  }

  return 0;
}