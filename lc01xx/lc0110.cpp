//--- Q: 0110. Balanced Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs with finding left & right max height from bottm to top, better
class Solution {
public:
    bool find = true;
    bool isBalanced(TreeNode* root) {
        postorder(root);
        return find;
    }
    int postorder(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int lv = postorder(root->left);
        int rv = postorder(root->right);
        if (abs(lv-rv) > 1) {
            find = false;
        }
        return max(lv, rv)+1;
    }
};
