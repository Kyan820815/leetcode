//--- Q: 0814. Binary Tree Pruning

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: postorder
class Solution {
public:
    TreeNode *pruneTree(TreeNode *root) {
        if (root->left) {
            root->left = pruneTree(root->left);
        }
        if (root->right) {
            root->right = pruneTree(root->right);
        }
        if (!root->left && !root->right && !root->val) {
            return nullptr;
        } else {
            return root;
        }
    }
};