//--- Q: Lowest Common Ancestor of Deepest Leaves

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: one pass 
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
    	int maxh;
    	return find(root, maxh);
    }
    TreeNode *find(TreeNode *root, int &h)
    {
    	h = 0;
    	if (!root)
    		return root;
    	int left_h, right_h;
    	TreeNode *left = find(root->left, left_h);
    	TreeNode *right = find(root->right, right_h);

    	h = max(left_h, right_h) + 1;

    	if (left_h == right_h)
    		return root;
    	else if (left_h > right_h)
    		return left;
		else
			return right;    
    }
};

//--- method 2: two pass 
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
    	int maxh = 0;
    	dfs(root, 0, maxh);
    	return find(root, 0, maxh);
    }
    void dfs(TreeNode *root, int h, int &maxh)
    {
    	if (h > maxh)
    		maxh = h;
    	if (root->left)
    		dfs(root->left, h+1, maxh);
    	if (root->right)
    		dfs(root->right, h+1, maxh);
    }
    TreeNode *find(TreeNode *root, int h, int maxh)
    {
    	if (!root || h == maxh)
    		return root;

    	TreeNode *left = find(root->left, h+1, maxh);
    	TreeNode *right = find(root->right, h+1, maxh);

    	if (left && right)
    		return root;
    	else if (!left && !right)
    		return NULL;
    	else if (!left)
    		return right;
    	else
    		return left;
    }
};