/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return isBalancedHelper(root).first;
    }
    pair<bool, int> isBalancedHelper(TreeNode* root) {
        if(root == NULL) return {true, 0};
        auto left = isBalancedHelper(root->left);
        auto right = isBalancedHelper(root->right);
        return {left.first && right.first && abs(left.second - right.second) <=1, 1 + max(left.second, right.second)};
    }
};
