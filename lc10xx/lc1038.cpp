//--- Q: 1038. Binary Search Tree to Greater Sum Tree

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
    TreeNode* bstToGst(TreeNode* root) {
		int sum = 0;
		if (!root) return root;
		dfs(root, sum);
		return root;
    }
    void dfs(TreeNode *root, int &sum)
    {
    	if (root->right)
    		dfs(root->right, sum);
    	sum += root->val;
    	root->val = sum;
    	if (root->left)
    		dfs(root->left, sum);
    }
};