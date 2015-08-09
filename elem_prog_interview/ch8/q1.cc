#include <iostream>
#include <limits>
using namespace std;

struct Node{
  int val;
  Node* next;
  Node(int x): val(x), next(NULL) {}
};

Node* MergeLinkLists(Node* a, Node* b) {

  Node* dummy = new Node(INT_MIN);
  Node* curr = dummy;
  int a_val, b_val; 
  while (a!= NULL || b!=NULL) {
    a_val = (a->val == NULL) ? INT_MAX : a -> val;
    b_val = (b->val == NULL) ? INT_MAX : b -> val;    

    if (a_val < b_val) {
      curr->next = a;
      a = a->next;
    } else {
      curr->next = b;
      b = b->next;
    }
    curr = curr->next;
  }
  return dummy->next;
}

void print(Node* a) {

  Node* tmp = a;
  while(tmp) {
    cout << tmp->val << "->";
  }
  cout << "NULL" << endl;
}

