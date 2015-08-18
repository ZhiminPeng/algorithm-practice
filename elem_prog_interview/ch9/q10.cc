// implement preorder and post order traversal
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// recursive solution
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        result.push_back(root->val);
        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);
        result.insert(result.end(), left.begin(), left.end());
        result.insert(result.end(), right.begin(), right.end());
        return result;
    }
};


// iterative solution
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* itr = root;
        stack<TreeNode*> my_stack;
        vector<int> result;
        if(itr == NULL) return result;
        my_stack.push(itr);
        while (!my_stack.empty()) {
            itr = my_stack.top();
            result.push_back(itr->val);
            my_stack.pop();
            if (itr->right) {
                my_stack.push(itr->right);
            }
            if (itr->left) {
                my_stack.push(itr->left);
            }
        }
        return result;
    }
};


// recursive solution
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        vector<int> left = postorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);
        result.insert(result.end(), left.begin(), left.end());
        result.insert(result.end(), right.begin(), right.end());
        result.push_back(root->val);
        return result;
    }
};

// iterative solution
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> my_stack;
        vector<int> result;
        if (root == NULL) return result;
        TreeNode* itr = root;
        my_stack.push(itr);
        while (!my_stack.empty()) {
            itr = my_stack.top();
            result.push_back(itr->val);
            my_stack.pop();
            if (itr->left) my_stack.push(itr->left);
            if (itr->right) my_stack.push(itr->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
