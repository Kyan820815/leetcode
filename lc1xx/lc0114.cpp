//--- Q: 114. Flatten Binary Tree to Linked List

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs recursion with double link list
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *dummy = new TreeNode(-1);
        if (!root) return; 
        dfs(root, &dummy);
    }
    void dfs(TreeNode *root, TreeNode **now)
    {
    	TreeNode *copy = NULL;
    	(*now)->right = root;
    	(*now)->left = NULL;
    	(*now) = (*now)->right;
    	copy = ((*now)->right) ? (*now)->right : copy;
    	if ((*now)->left)
    		dfs((*now)->left, now);
    	if (copy)
    		dfs(copy, now);
    }
};

//--- method 2: dfs recursion with single link list
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *dummy = new TreeNode(-1);
        if (!root) return; 
        dummy = dfs(root, dummy);
    }
    TreeNode *dfs(TreeNode *root, TreeNode *now)
    {
    	TreeNode *copy = NULL;
    	now->right = root;
    	now->left = NULL;
    	now = now->right;
    	copy = (now->right) ? now->right : copy;
    	if (now->left)
    		now = dfs(now->left, now);
    	if (copy)
    		now = dfs(copy, now);
    	return now;
    }
};

//--- method 3: iteration
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *left, *right, *cur;
        while(root)
        {
        	left = root->left;
        	right = root->right;
        	if (!left)
        		root = root->right;
			else
			{
				cur = left;
				while(cur->right)
					cur = cur->right;
				cur->right = right;

                root->left = NULL;
                root->right = left;
                root = root->right;         
			}
        }
    }
};