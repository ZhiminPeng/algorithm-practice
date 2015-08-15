// implement a queue using stack
#include <stack>
#include <stdexcept>
#include <iostream>

using namespace std;

class Queue{
  stack<int> A_, B_;

 public:  

  void Enqueue(int x) {
    A_.push(x);
  }

  int Dequeue() {
    if (B_.empty()) {
      while(!A_.empty()) {
        int val = A_.top();
        B_.push(val);
        A_.pop();
      }
    }

    if (B_.empty()) {
      throw length_error("ERROR: empty queue! \n");
    }
    int val = B_.top();
    B_.pop();
    return val;
  }

};


int main() {

  Queue my_queue;
  my_queue.Enqueue(1);
  my_queue.Enqueue(2);
  my_queue.Enqueue(3);  

  cout << my_queue.Dequeue() << endl;
  cout << my_queue.Dequeue() << endl;
  cout << my_queue.Dequeue() << endl;  
  
}
