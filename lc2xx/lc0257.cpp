//--- Q: 257. Binary Tree Paths

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string now;
        if (root) dfs(root, res, now);
        return res;
    }
    void dfs(TreeNode * root, vector<string> &res, string now)
    {
    	now = now + to_string(root->val);
    	if (!root->left && !root->right)
    	{
    		res.push_back(now);
    		return;
    	}
    	else
    	{
    		now += "->";
    		if (root->left)
    			dfs(root->left, res, now);
    		if (root->right)
    			dfs(root->right, res, now);
    	}
    }
};