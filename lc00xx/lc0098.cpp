//--- Q: 098. Validate Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dynamically allocate min and max of current node, better
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        bool valid = true;
        dfs(root, LONG_MIN, LONG_MAX, valid);
        return valid;
    }
    void dfs(TreeNode *root, long int min, long int max, bool &valid)
    {
    	if (!root) return;
    	if (root->val <= min || root->val >= max)
    	{
    		valid = false;
    		return;
    	}
    	if (root->left)
    		dfs(root->left, min, root->val, valid);
    	if (valid && root->right)
    		dfs(root->right,  root->val, max, valid);
    	if (!valid) return;
    }
};

//--- method 2: inorder traversal
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        bool valid = true, first = false;
        int last = INT_MIN;
        if (!root) return valid;
        inorder(root, last, first, valid);
        return valid;
    }
    void inorder(TreeNode *root, int &last, bool &first, bool &valid)
    {
    	if (root->left)
    		inorder(root->left, last, first, valid);
    	if (first && root->val <= last)
    	{
    		valid = false;
    		return;
    	}
        first = true;
    	last = root->val;
    	if (root->right)
    		inorder(root->right, last, first, valid);
    }
};