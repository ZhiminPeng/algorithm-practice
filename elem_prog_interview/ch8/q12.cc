// Implement odd-even merge
ListNode* EvenOddMerge(ListNode* head) {

  ListNode* even_dummy = New ListNode(-1);
  ListNode* odd_dummy = New ListNode(-1);  

  ListNode* curr = head;

  int idx = 0;
  while (curr) {

    if (idx % 2 == 0) {
      even_dummy->next = curr;
      even_dummy = even_dummy->next;
    } else {
      odd_dummy->next = curr;
      odd_dummy = odd_dummy->next;
    }
    ++idx;
    curr = curr->next;
  }

  ListNode* even_tail = even_dummy;
  while (even_tail->next) {
    even_tail = even_tail->next;
  }
  even_tail->next = odd_dummy->next;
  return even_dummy->next;
}
