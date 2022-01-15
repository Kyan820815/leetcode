//--- Q: 1026. Maximum Difference Between Node and Ancestor

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: preorder to find min and max of root to leaf
class Solution {
public:
    int minv = INT_MAX, maxv = INT_MIN, res = 0;
    int maxAncestorDiff(TreeNode* root) {
        preorder(root, minv, maxv);
        return res;
    }
    void preorder(TreeNode *root, int minv, int maxv) {
        minv = min(minv, root->val);
        maxv = max(maxv, root->val);
        res = max(res, abs(maxv-minv));
        if (root->left) {
            preorder(root->left, minv, maxv);
        }
        if (root->right) {
            preorder(root->right, minv, maxv);
        }
    }
};