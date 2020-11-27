//--- Q: 814. Binary Tree Pruning

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
    TreeNode* pruneTree(TreeNode* root) {
        return dfs(root);
    }
    TreeNode *dfs(TreeNode *root)
    {
    	if (root->left)
    		root->left = dfs(root->left);
    	if (root->right)
    		root->right = dfs(root->right);

    	if (root->val == 0 && !root->left && !root->right)
    		root = NULL;
    	return root;
    }
};