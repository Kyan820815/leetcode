//--- Q: 110. Balanced Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs with finding left & right max height from bottm to top, better
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return (dfs(root) == -1) ? false : true;
    }
    int dfs(TreeNode *root)
    {
    	int l, r;
    	if (!root) return 0;

		l = dfs(root->left);
		if (l == -1) return -1;

   		r = dfs(root->right); 
		if (r == -1) return -1;

    	if (abs(l-r) > 1)
    		return -1;
    	else return max(l,r)+1;
    }
};

//--- method 2: dfs with finding left & right max depth from top to bottom
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height = 0;
        bool bbt = true;
        if (!root) return true;
        dfs(root, height, bbt);
        return bbt;
    }
    void dfs(TreeNode *root, int &height, bool &bbt)
    {
    	int l, r;
    	l = r = height;
    	if (root->left)
    	{
    		l++;
    		dfs(root->left, l, bbt);
    		if (!bbt) return;
    	}
       
    	if (root->right)
    	{
    		r++;
    		dfs(root->right, r, bbt); 
    		if (!bbt) return;
    	}
    	height = max(l,r);
    	if (abs(l-r) > 1)
    	{
    		bbt = false;
    		return;
    	}
    }
};