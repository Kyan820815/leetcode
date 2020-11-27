//--- Q: 226. Invert Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1:
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    	if (!root) return root;
        dfs(root);
    	return root;
    }
    void dfs(TreeNode *root)
    {
    	TreeNode *copy;
    	if (!root->left && !root->right)
    		return;
    	else
    	{
    		copy = root->left;
    		root->left = root->right;
    		root->right = copy;
    		if (root->left)
    			dfs(root->left);
    		if (root->right)
    			dfs(root->right);
    	}
    }
};