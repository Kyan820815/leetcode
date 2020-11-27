//--- Q: 404. Sum of Left Leaves

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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        dfs(root, res, 0);
        return res;
    }
    void dfs(TreeNode *root, int &res, int left)
    {
    	if (left && !root->left && !root->right)
    		res += root->val;
    	if (root->left)
    	{
    		dfs(root->left, res, 1);
    	}
    	if (root->right)
    		dfs(root->right, res, 0);
    }
};