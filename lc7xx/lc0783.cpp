//--- Q: 783. Minimum Distance Between BST Nodes

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: inorder traversal
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int diff = INT_MAX, last = INT_MIN;
        inorder(root, diff, last);
        return diff;
    }
    void inorder(TreeNode *root, int &diff, int &last)
    {
    	if (root->left)
    		inorder(root->left, diff, last);
    	if (last != INT_MIN)
    		diff = min(diff, abs(root->val-last));
    	last = root->val;
    	if (root->right)
    		inorder(root->right, diff, last);
    }
};