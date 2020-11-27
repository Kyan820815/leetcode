//--- Q: 530. Minimum Absolute Difference in BST

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: inorder
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int last = INT_MIN, diff = INT_MAX;
        inorder(root, last, diff);
        return diff;
    }
    void inorder(TreeNode *root, int &last, int &diff)
    {
    	if (root->left)
    		inorder(root->left, last, diff);
    	if (last != INT_MIN && diff > root->val-last)
    		diff = root->val-last;
    	last = root->val;
    	if (root->right)
    		inorder(root->right, last, diff);
    }
};

//--- method 2: preorder
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX;
        preorder(root, INT_MIN, INT_MAX, diff);
        return diff;
    }
    void preorder(TreeNode *root, int minv, int maxv, int &diff)
    {
    	if (maxv != INT_MAX)
    		diff = min(diff, maxv-root->val);
    	if (minv != INT_MIN)
    		diff = min(diff, root->val-minv);
    	if (root->left)
    		preorder(root->left,  minv, root->val, diff);
    	if (root->right)
    		preorder(root->right, root->val, maxv, diff);
    }
};