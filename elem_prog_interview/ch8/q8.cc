struct ListNode {
  int val;
  ListNode* next;
};

// delete a node from a list with O(1) time
void DeleteNode(Node* mynode) {
  mynode->val = mynode->next->val;
  mynode->next = mynode->next->next;
}
