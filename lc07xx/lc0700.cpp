//--- Q: 700. Search in a Binary Search Tree

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root || root->val == val) return root;
        if (root->val < val)
        	return searchBST(root->right, val);
        else
        	return searchBST(root->left, val);
    }
};

//--- method 2: iteration
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
		while (root && root->val != val)
		{
			if (root->val < val) root = root->right;
			else root = root->left;
		}
		return root;
    }
};