// implement list zipping
ListNode* ZippingLinkedList(ListNode* head) {

  if(!head || !head->next) {
    return head;
  }

  ListNode* slow = head;
  ListNode* fast = head;

  while (fast || fast->next) {
    fast = fast->next->next;
    slow = slow->next;
  }
  ListNode* second_half_head = slow->next;

  second_half_head = ReverseLinkedList(second_half_head);

  ListNode* first_half_itr = head;
  ListNode* second_half_itr = second_half_head;

  while (second_half_itr) {
    ListNode* tmp = second_half_itr->next;
    second_half_itr->next = first_half_itr->next;
    first_half_itr->next = second_half_itr;
    first_half_itr = first_half_itr->next->next;
    second_half_itr = tmp;
  }

  return head;
}
