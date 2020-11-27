//--- Q: 111. Minimum Depth of Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1-1: choose path method
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
    	if (!root->left) return minDepth(root->right)+1;
    	if (!root->right) return minDepth(root->left)+1;
    	return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

//--- method 1-2: INT_MAX method
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
    	if (!root->left && !root->right) return 1;
    	return min((root->left ? minDepth(root->left) : INT_MAX), (root->right ? minDepth(root->right) : INT_MAX)) + 1;
    }
};