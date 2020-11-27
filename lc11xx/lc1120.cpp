//--- Q: 1120. Maximum Average Subtree

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
    double maximumAverageSubtree(TreeNode* root) {
        double res = 0, now;
        postorder(root, res, now);
        return res;
    }
    int postorder(TreeNode *root, double &res, double &now) {
        int l = 0, r = 0;
        double lv = 0, rv = 0;
        if (root->left)
            l = postorder(root->left, res, lv);
        if (root->right)
            r = postorder(root->right, res, rv);
        
        res = max(res, (root->val+lv+rv) / (l+r+1));
        now = root->val + lv + rv;
        return l+r+1;
    }
};