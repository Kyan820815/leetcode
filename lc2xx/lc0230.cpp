//--- Q: 230. Kth Smallest Element in a BST

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs recursion
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
    	int find, now = 0;
    	dfs(root, k, now, find);
    	return find;   
    }
    void dfs(TreeNode *root, int k, int &now, int &find)
    {
    	if (root->left)
    		dfs(root->left, k, now, find);
    	now++;
        if (k == now)
    	{
    		find = root->val;
    		return;
    	}
    	if (root->right)
    		dfs(root->right, k, now, find);
    }
};

//--- method 2: stack iteration
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
    	int now = 0;
    	TreeNode *cur;
    	stack<TreeNode *> sk;
    	cur = root;
    	while (cur || sk.size() != 0)
    	{
    		while (cur)
    		{
    			sk.push(cur);
    			cur = cur->left;
    		}
    		if (!cur)
    		{
    			cur = sk.top();
    			sk.pop();
    			now++;
    			if (now == k)
    				return cur->val;
    			cur = cur->right;
    		}
    	}
    	return 0;   
    }
};

//--- method 3: morris traversal
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
    	int now = 0, find;
    	TreeNode *cur;
    	cur = root;
    	while (cur)
    	{
    		if (cur->left)
    		{
    			TreeNode *pre = cur;
    			cur = cur->left;
    			while (cur->right != pre && cur->right != NULL)
    				cur = cur->right;
    			if (cur->right == pre)
    			{
    				cur->right = NULL;
    				if (++now == k)
						find = pre->val;    					
    				cur = pre->right;
    			}
    			else
    			{
    				cur->right = pre;
    				cur = pre->left;
    			}
    		}
    		else
    		{
    			if (++now == k)
    				find = cur->val;
    			cur = cur->right;
    		}
    	}
    	return find;
    }
};