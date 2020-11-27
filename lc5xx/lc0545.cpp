//--- Q: 545. Boundary of Binary Tree

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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (!root)
            return {};
        res.push_back(root->val);
        postorder(root->left, res, true, false);
        postorder(root->right, res, false, true);
        return res;
    }
    void postorder(TreeNode *root, vector<int> &res, bool left, bool right) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            res.push_back(root->val);
            return;            
        }
        if (left)
            res.push_back(root->val);
        if (root->left)
            postorder(root->left, res, left && root->left, right && !root->right);
        if (root->right)
            postorder(root->right, res, left && !root->left, right && root->right);
        if (right)
            res.push_back(root->val);
    }
};