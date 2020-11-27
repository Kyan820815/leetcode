//--- Q: 993. Cousins in Binary Tree

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
    bool isCousins(TreeNode* root, int x, int y) {
    	int lh, rh, lp, rp;
    	TreeNode *dummy = new TreeNode(-1), *pre;
    	dummy->left = root;
    	pre = dummy;
    	lh = rh = lp = rp = 0;
    	preorder(root, pre, x, y, 0, lh, rh, lp, rp);
    	return (lp != rp && lh == rh) ? true : false; 
    }
    void preorder(TreeNode *root, TreeNode *pre, int x, int y, int h, int &lh, int &rh, int &lp, int &rp)
    {
    	if (root->val == x)
    	{
    		lh = h;
    		lp = pre->val;
    	}
    	else if (root->val == y)
    	{
    		rh = h;
    		rp = pre->val;
    	}
    	if (root->left)
    		preorder(root->left, root, x, y, h+1, lh, rh, lp, rp);
    	if (root->right)
    		preorder(root->right, root, x, y, h+1, lh, rh, lp, rp);
    }
};