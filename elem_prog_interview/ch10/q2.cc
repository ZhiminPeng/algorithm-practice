// check K balance tree

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
 TreeNode: val(0), left(NULL), right(NULL) {}
};




pair<TreeNode*, int> FindKBalanceNodeHelper(TreeNode* head, int k) {

  // base case
  if (head == NULL) {
    return {NULL, 0};
  }

  auto left_res = FindKBalanceNodeHelper(head->left, k);
  auto right_res = FindKBalanceNodeHelper(head->right, k);  

  if (left_res.first) {
    return {left_res.first, 0};
  }

  if (right_res.first) {
    return {right_res.first, 0}
  }

  int num_nodes = left_res.second + right_res.second + 1;

  bool is_KBalance = abs(left_res.first - right_res.first) <= k;

  return is_KBalance ? {NULL, num_nodes} : {head, num_nodes};

}


TreeNode* FindKBalanceNode(TreeNode* head, int k) {

  return FindKBalanceNodeHelper(head, k).first;

}
