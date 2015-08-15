// implement a queue using stack with max API

#include <stack>
#include <utility>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <climits>
using namespace std;

class Stack{
  stack<pair<int, int> > data_;
  
public:
  
  int Max(){
    if(data_.empty()) {
      throw length_error("ERROR: empty stack! \n");
    }
    return data_.top().second;
  }

  void Push(int x) {
    data_.emplace(x, data_.empty() ? x : max(x, Max() ) );
  }

  int Pop() {
    if (data_.empty()) {
      throw length_error("ERROR: empty stack!");
    } else {
      int val = data_.top().first;
      data_.pop();
      return val;
    }
  }
  
  bool Empty() {
    return data_.empty();
  }
  
};

class Queue{

  Stack A_, B_;

 public:

  int Max() {
    if(A_.Empty() && B_.Empty() ) {
      throw length_error("ERROR: empty queue! \n");
    }
    
    int max_A = A_.Empty() ? INT_MIN : A_.Max();
    int max_B = B_.Empty() ? INT_MIN : B_.Max();    
    return max(max_A, max_B);
  }

  void Enqueue(int x) {
    A_.Push(x);
  }

  int Dequeue() {

    if(B_.Empty()) {
      while(!A_.Empty()) {
        B_.Push(A_.Pop());
      }
    }

    if(B_.Empty()) {
      throw length_error("ERROR: empty queue! \n");
    }

    B_.Pop();

  }

};


int main(int argc, char *argv[])
{
  Queue my_queue;
  my_queue.Enqueue(1);
  my_queue.Enqueue(3);
  my_queue.Enqueue(2);

  cout << my_queue.Max() << endl;
  
  return 0;
}
