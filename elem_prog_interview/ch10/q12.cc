/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// create a binary tree based on preorder and inorder traversal
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, inorder, 0, inorder.size(), 0, preorder.size());
        
    }
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int in_start, int in_end, int pre_start, int pre_end) {
        if (in_start >= in_end || pre_start >= pre_end) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[pre_start]);
        int i = 0;
        for (i = in_start; i < in_end; i++) {
            if (inorder[i] == preorder[pre_start]) break;
        }
        int len = i - in_start; 
        TreeNode* left = buildTreeHelper(preorder, inorder, in_start, in_start + len, pre_start + 1, pre_start + 1 + len);
        TreeNode* right = buildTreeHelper(preorder, inorder, i + 1, in_end, pre_start + len + 1, pre_end);
        root->left = left;
        root->right = right;
        return root;
        
    }
};
