//--- Q: 99. Recover Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: O(1) space, morris traversal
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *now = root;
        TreeNode *pre, *first, *second;
        pre = first = second = NULL;
        while (now)
        {
        	if (now->left)
        	{
        		TreeNode *parent = now;
        		now = now->left;
        		while (now->right && now->right != parent)
        			now = now->right;
        		if (!now->right)
        		{
        			now->right = parent;
        			now = parent->left;
        		}
        		else
        		{
        			now->right = NULL;
        			if (pre && pre->val > parent->val)
        			{
        				if (!first)
        					first = pre;
        				second = parent;
        			}
        			pre = parent;
        			now = parent->right;
        		}
        	}
        	else
        	{
        		if (pre && pre->val > now->val)
        		{
        			if (!first)
        				first = pre;
        			second = now;
        		}
        		pre = now;
        		now = now->right;
        	}
        }
        swap(first->val, second->val);
    }
};

//--- method 2-1: O(N) space bfs
class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode *> sk;
        TreeNode *now = root;
        TreeNode *pre = NULL, *first = NULL, *second = NULL;
        while (sk.size() || now)
        {
        	while (now)
        	{
        		sk.push(now);
        		now = now->left;
        	}
        	now = sk.top();
        	sk.pop();
        	if (pre && now->val < pre->val)
        	{
    			if (!first)
    				first = pre;
    			second = now;
        	}
        	pre = now;
        	now = now->right;
        }
        swap(first->val, second->val);
    }
};

//--- method 2-2: O(n) space dfs
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *pre, *first, *second;
        pre = first = second = NULL;
        preorder(root, &pre, &first, &second);
        swap(first->val, second->val);
    }
    void preorder(TreeNode *root, TreeNode **pre, TreeNode **first, TreeNode **second)
    {
    	if (root->left)
    		preorder(root->left, pre, first, second);
    	if (*pre && (*pre)->val > root->val)
    	{
    		if (!*first)
    			*first = *pre;
    		*second = root;
    	}
    	*pre = root;
    	if (root->right)
    		preorder(root->right, pre, first, second);
    }
};