//--- Q: 0112. Path Sum
//--- last written: 2023/07/13

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: recursive solution
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
        if (!root->left && !root->right) {
            return !(targetSum-root->val);
        }
        if (!root->left) {
            return hasPathSum(root->right, targetSum-root->val);
        } else if (!root->right) {
            return hasPathSum(root->left, targetSum-root->val);
        }
        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }
};