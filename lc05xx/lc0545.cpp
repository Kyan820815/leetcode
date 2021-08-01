//--- Q: 0545. Boundary of Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: postorder recursion with path recoding
class Solution {
public:
    vector<int> res;
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        res.push_back(root->val);
        preorder(root->left, 1, 0);
        preorder(root->right, 0, 1);
        return res;
    }
    void preorder(TreeNode *root, int left, int right) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            res.push_back(root->val);
            return;
        }
        if (left) {
            res.push_back(root->val);
        }
        preorder(root->left, left, right && !root->right);
        preorder(root->right, left && !root->left, right);
        if (right) {
            res.push_back(root->val);
        }
    }
};