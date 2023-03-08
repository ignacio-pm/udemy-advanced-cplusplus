#include <iostream>
#include <map>
using namespace std;

// Difference between struct and class is that the default accessibility of classes is private 
class personalData {
  
  private: 
    int age;
    int height;
    double weight;
  
  public:
    personalData() {}
    personalData(int age, int height, double weight) : age(age), height(height), weight(weight) {}
    // Const is necessary if using the struct as key
    void print() const {
      cout << "Data: " << age << ", " << height << ", " << weight << endl;
    }
    // The operator override is necessary if using the struct as key
    bool operator< (const personalData &other) const {
      // Return all the values that make the key unique.
      if (age == other.age) {
        return height < other.height;
      } else {
        return age < other.age;
      }
    }
};

int main() {
  map<string, personalData> completeData;
  // Add items with operator overloading or insert function to the map
  // This only works in C++11 due to uniform initialization. If not, create constructor of struct
  // completeData["Peters"] = personalData(30, 170, 89.3);
  completeData["Peters"] = {30, 170, 89.3};
  completeData["Jack"] = {40, 168, 60.6};
  completeData.insert(make_pair("Adrian", personalData{28, 175, 74.5}));
  // Alternative: 
  // completeData.insert(pair<string,personalData>("Adrian", {28, 175, 74.5}));

  // Look for key in map
  string person = "Jack";
  if (completeData.find(person) != completeData.end()) {
    cout << "Found Jack with : " << endl;
    completeData[person].print();
  } else {
    cout << "No personal data from the name " << person << " found!" << endl;
  }

  // Loop through the map and print age and weight
  for(map<string,personalData>::iterator it = completeData.begin(); it != completeData.end(); it++) {
    cout << it->first << " with " << flush;
    it->second.print();
    // Alternative:
    // pair<string,personalData> pairData = *it;
    // cout << pairData.first << " with " << endl;
    // pairData.print();
  }

  map <personalData, int> dataAsKey;

  // Depending on the operator < a new item will be added or the key information will be lost.
  dataAsKey[personalData(20, 160, 82.5)] = 10;
  dataAsKey[personalData(20, 170, 89.3)] = 100;

  for(map<personalData, int>::iterator it = dataAsKey.begin(); it != dataAsKey.end(); it++) {
    cout << it->second << " with " << flush;
    it->first.print();
  }

  
  return 0;
}