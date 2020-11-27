//--- Q: 112. Path Sum

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
    bool hasPathSum(TreeNode* root, int sum) {
		if (!root) return false;
		if (!root->left && !root->right)
	    	if (sum == root->val) return true;
		if (!root->left) return hasPathSum(root->right, sum-root->val);
		if (!root->right) return hasPathSum(root->left, sum-root->val);
		return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};