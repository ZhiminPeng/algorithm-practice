// implement a stack with max API
#include <stack>
#include <utility>
#include <algorithm>
#include <iostream>
#include <stdexcept>
using namespace std;

class Stack{
  stack<pair<int, int> > data_;
  
public:  
  int Max(){
    if(data_.empty) {
      throw length_error("ERROR: empty stack! \n");
    }
    return data_.top().second;
  }

  void Push(int x) {
    data_.emplace(x, data_.empty() ? x : max(x, Max() ) );
  }

  int Pop() {
    if (data_.empty()) {
      throw length_error("ERROR: empty stack! \n");
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

int main() {
  Stack my_stack;
  my_stack.Push(0);
  cout << my_stack.Max() << endl;
  my_stack.Push(1);  
  cout << my_stack.Pop() << endl;

}
