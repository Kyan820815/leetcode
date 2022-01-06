//--- Q: 0951. Flip Equivalent Binary Trees

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: clean code, dfs recursion
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return true;
        } else if (!root1 || !root2 || root1->val != root2->val) {
            return false;
        }
        return flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)
            || flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
    }
};