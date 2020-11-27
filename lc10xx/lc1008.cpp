//--- Q: 1008. Construct Binary Search Tree from Preorder Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: stack iteration
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode *> sk;
        TreeNode *tmp = NULL, *root;
        int idx = 1;
        if (!preorder.size())
        	return NULL;
        root = new TreeNode(preorder[0]);
        sk.push(root);

        while (idx < preorder.size())
        {
        	if (!sk.size() || preorder[idx] < sk.top()->val)
        	{
        		if (!tmp)
        		{
	        		sk.top()->left = new TreeNode(preorder[idx]);
    	    		sk.push(sk.top()->left);
        		}
        		else
        		{
        			tmp->right = new TreeNode(preorder[idx]);
        			sk.push(tmp->right);
        			tmp = NULL;
        		}
        		++idx;
        	}
        	else
        	{
        		tmp = sk.top();
        		sk.pop();
        	}
        }
        return root;
    }
};

//--- method 2: dfs recursion
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
    	int idx = 0;
    	if (!preorder.size()) return NULL;
    	TreeNode *root = new TreeNode(preorder[0]);

    	for (int i = 1; i < preorder.size(); ++i)
    		dfs(root, preorder[i]);

       return root;
    }
    void dfs(TreeNode *root, int val)
    {
    	if (root->val > val)
    	{
    		if (!root->left)
    			root->left = new TreeNode(val);
    		else
    			dfs(root->left, val);
    	}
    	else
    	{
    		if (!root->right)
    			root->right = new TreeNode(val);
    		else
    			dfs(root->right, val);
    	}
    }
};