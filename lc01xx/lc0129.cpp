//--- Q: 0129. Sum Root to Leaf Numbers
//--- last written: 2023/07/14

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs recursion
class Solution {
public:
    int res = 0;
    int sumNumbers(TreeNode* root) {
        preorder(root, 0);
        return res;
    }
    void preorder(TreeNode *root, int val) {
        val = val*10 + root->val;
        if (!root->left && !root->right) {
            res += val;
        }
        if (root->left) {
            preorder(root->left, val);
        }
        if (root->right) {
            preorder(root->right, val);
        }
    }
};
