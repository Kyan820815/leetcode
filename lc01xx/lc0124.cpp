//--- Q: 124. Binary Tree Maximum Path Sum

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
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        postorder(root);
        return res;
    }
    int postorder(TreeNode *root) {
        int lv = 0, rv = 0;
        if (root->left) {
            lv = max(postorder(root->left), 0);
        }
        if (root->right) {
            rv = max(postorder(root->right), 0);
        }
        int val = root->val + lv + rv;
        res = max(res, val);
        return root->val + max(lv, rv);
    }
};