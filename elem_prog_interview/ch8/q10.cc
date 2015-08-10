ListNode* RemoveDuplicates(ListNode* head) {
  ListNode* curr = head;
  while (curr) {
    ListNode* next = curr->next;

    while (next && next->val == curr->val) {
      next = next->next;
    }

    curr->next = next;
    curr = next;
  }
  return head;
}
