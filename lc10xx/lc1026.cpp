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
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        int diff = 0, minv = INT_MAX, maxv = INT_MIN;
        preorder(root, diff, minv, maxv);
        return diff;
    }
    void preorder(TreeNode *root, int &diff, int minv, int maxv)
    {
    	minv = min(minv, root->val);
    	maxv = max(maxv, root->val);
    	if (root->left)
    		preorder(root->left, diff, minv, maxv);
    	if (root->right)
    		preorder(root->right, diff, minv, maxv);
    	if (!root->left && !root->right)
    		diff = max(diff, abs(minv-maxv));
    }
};