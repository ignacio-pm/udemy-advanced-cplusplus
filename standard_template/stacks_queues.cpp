#include <iostream>
#include <stack>
#include <queue>
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
};

int main() {
  // Container adaptor with LIFO. Not possible to iterate through it (only last element with top())
  stack<personalData> dataStack;
  // Objects are destroyed and creating shallow copies when they are pushed to a stack / queue
  dataStack.push(personalData(10, 140, 35.3));
  dataStack.push(personalData(15, 155, 48.5));
  dataStack.push(personalData(20, 170, 65.7));
  
  cout << "Stack order:" << endl;

  // Alternative: 
  // while(!dataStack.empty()) {
  while(dataStack.size() > 0) {
    // Creating a reference is more efficient because a new object is not created
    personalData &lastData = dataStack.top();
    lastData.print();
    // If a reference is created, it can not be used after the item was popped
    dataStack.pop();
  }

  cout << "---------" << endl;

  // Same as stack but FIFO. It is possible to get first and last item with front() and back()
  queue<personalData> dataQueue;
  dataQueue.push(personalData(10, 140, 35.3));
  dataQueue.push(personalData(15, 155, 48.5));
  dataQueue.push(personalData(20, 170, 65.7));

  // Back instead of top to get the last item
  personalData &lastQueueData = dataQueue.back();
  cout << "Last from queue: " << endl;
  lastQueueData.print();

  cout << "---------" << endl;
  cout << "Queue order:" << endl;

  while(!dataQueue.empty()) {
    personalData &firstData = dataQueue.front();
    firstData.print();
    dataQueue.pop();
  }

  return 0;
}