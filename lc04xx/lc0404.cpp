//--- Q: 0404. Sum of Left Leaves

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs
class Solution {
public:
    int res = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        preorder(root);
        return res;
    }
    void preorder(TreeNode *root) {
        if (root->left && !root->left->left && !root->left->right) {
            res += root->left->val;
        }
        if (root->left) {
            preorder(root->left);
        }
        if (root->right) {
            preorder(root->right);
        }
    }
};