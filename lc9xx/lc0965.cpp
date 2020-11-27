//--- Q: 965. Univalued Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: preorder recursion
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        bool find = true;
        if (root->left) {
            if (root->left->val == root->val)
                find &= isUnivalTree(root->left);
            else
                return false;
        }
        if (root->right) {
            if (root->right->val == root->val)
                find &= isUnivalTree(root->right);
            else
                return false;
        }
        return find;
    }
};