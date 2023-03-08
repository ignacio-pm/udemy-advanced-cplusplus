#include <iostream>
#include <vector>
using namespace std;

class personalData {

  private: 
    int age;
    int height;
    double weight;
  
  public:
    personalData() {}
    personalData(int age, int height, double weight) : age(age), height(height), weight(weight) {}
    void print() {
      cout << "Data: " << age << ", " << height << ", " << weight << endl;
    }
    bool operator< (const personalData &other) const {
      // Return all the values that make the key unique
      if (age == other.age) {
        return height < other.height;
      } else {
        return age < other.age;
      }
    }
    // To sort a vector, an alternative to overwrite the operator < is to declare a compare function
    // Friend declaration is used to access the private and protected data from an external function
    friend bool compareWeight(const personalData &a, const personalData &b);
};

bool compareWeight (const personalData &a, const personalData &b) {
  return a.weight < b.weight;
}

int main() {
  vector<personalData> vData;
  vData.push_back(personalData(50, 178, 79.5));
  vData.push_back(personalData(40, 190, 89.5));
  vData.push_back(personalData(60, 165, 57.0));
  vData.push_back(personalData(30, 146, 42.8));

  // Sort the first 3 items of the vector with the condition of the operator <
  // sort(vData.begin(),vData.begin()+3);

  // Sort with the custom compare function by passing the function pointer
  sort(vData.begin(),vData.end(), compareWeight);
  
  for(vector<personalData>::iterator it = vData.begin(); it != vData.end(); it++) {
    it->print();
  }

  // It is not efficient to sort after every insertion. If you need to, use set or another container
  
  return 0;
}