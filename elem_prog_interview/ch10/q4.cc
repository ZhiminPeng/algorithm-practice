/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// find the lowest common ancestor
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto result = lcaHelper(root, p, q);
        return result.first;
    }
    pair<TreeNode*, int> lcaHelper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return {NULL, 0};
        auto left = lcaHelper(root->left, p, q);
        auto right = lcaHelper(root->right, p, q);
        if (left.second == 2) {
            return left;
        }
        if (right.second == 2) {
            return right;
        }
        int num_valid_nodes = left.second + right.second + (root == p || root == q);
        return {num_valid_nodes == 2 ?root:NULL, num_valid_nodes};
    }
};
