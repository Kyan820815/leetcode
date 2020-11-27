//--- Q: 1145. Binary Tree Coloring Game

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
	int left, right;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        dfs(root, x);
        return max(max(left, right), n-left-right-1) > n/2;
    }
    int dfs(TreeNode *root, int x)
    {
    	int l = 0, r = 0;
    	if (root->left)
    		l = dfs(root->left, x);
    	if (root->right)
    		r = dfs(root->right, x);
    	if (root->val == x)
    	{
    		left = l;
    		right = r;
    	}
    	return l+r+1;
    }
};