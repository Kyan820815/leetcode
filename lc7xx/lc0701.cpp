//--- Q: 701. Insert into a Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
        {
        	root = new TreeNode(val);
        	return root;
        }
        dfs(root, val);
        return root;
    }
    void dfs(TreeNode *root, int val)
    {
    	if (root->val < val)
    	{
    		if (root->right)
    			dfs(root->right, val);
    		else
    			root->right = new TreeNode(val);
    	}
    	else
    	{
    		if (root->left)
    			dfs(root->left, val);
    		else
    			root->left = new TreeNode(val);
    	}
    }
};