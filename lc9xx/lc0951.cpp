//--- Q: 951. Flip Equivalent Binary Trees

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: clean code, better
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        bool find = true;
        if (!root1 && !root2) return true;
        else if (!root1 || !root2 || root1->val != root2->val) return false;
        return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)
        	|| flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
    }
};

//--- method 2: step by step dfs operation 
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        bool find = true;
        if (!root1 && !root2) return true;
        else if (!root1 || !root2) return false;
        dfs(root1, root2, find);
        return find;
    }
    void dfs(TreeNode *root1, TreeNode *root2, bool &find)
    {
    	int root1_c = 0, root2_c = 0;
    	if (root1->val != root2->val)
    	{
    		find = false;
    		return;
    	}
    	if (!root1->left && !root1->right && !root2->left && !root2->right)
    		return;
    	if (!root1->left)
    		++root1_c;
    	if (!root1->right)
    		++root1_c;
    	if (!root2->left)
    		++root2_c;
    	if (!root2->right)
    		++root2_c;
    	if (root1_c != root2_c)
    	{
    		find = false;
    		return;
    	}
    	if (root1_c == 0)
    	{
    		if (root1->left->val == root2->left->val)
    		{
    			if (root1->right->val != root2->right->val)
    			{
    				find = false;
    				return;
    			}
    		}
    		else if (root1->left->val == root2->right->val)
    		{
    			if (root1->right->val != root2->left->val)
    			{
    				find = false;
    				return;
    			}
    			else swap(root1->left, root1->right);
    		}
    	}
    	else
    	{
    		if (!root1->left)
    		{
    			if (!root2->left)
    			{
    				if (root1->right->val != root2->right->val)
	    			{
	    				find = false;
	    				return;
	    			}
    			}
    			else
    			{
    				if (root1->right->val != root2->left->val)
	    			{
	    				find = false;
	    				return;
	    			}
	    			else swap(root1->left, root1->right);
    			}
    		}
    		else
    		{
    			if (!root2->right)
    			{
    				if (root1->left->val != root2->left->val)
	    			{
	    				find = false;
	    				return;
	    			}
    			}
    			else
    			{
    				if (root1->left->val != root2->right->val)
	    			{
	    				find = false;
	    				return;
	    			}
	    			else swap(root1->left, root1->right);
    			}
    		}
    	}
    	
    	if (root1->left)
    		dfs(root1->left, root2->left, find);
    	if (root1->right)
    		dfs(root1->right, root2->right, find);
    }
};