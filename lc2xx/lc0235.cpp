//--- Q: 235. Lowest Common Ancestor of a Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: bst with comparing max and min, recursion
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val < min(p->val, q->val))
        	return lowestCommonAncestor(root->right, p, q);
        else if (root->val > max(p->val, q->val))
        	return lowestCommonAncestor(root->left, p, q);
        else return root;
    }
};

//--- method 1: bst with comparing max and min, iteration
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	while (true)
    	{
	        if (root->val < min(p->val, q->val))
	        	root = root->right;
	        else if (root->val > max(p->val, q->val))
	        	root = root->left;
	        else break;
    	}
    	return root;
    }
};