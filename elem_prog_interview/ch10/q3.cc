// Check if the tree is symmetric

bool CheckSymmetric(TreeNode* first, TreeNode* second) {

  if (first == NULL && second == NULL) {
    return true;
  } else if (first != NULL && second != NULL) {
    return first->val == second->val
        && CheckSymmetric(first->left, second->right)
        && CheckSymmetric(first->right, second->left);
  } else {
    return false;
  }
}

bool IsSymmetric(TreeNode* head) {

  return head == NULL || CheckSymmetric(head->left, head->right);

}
