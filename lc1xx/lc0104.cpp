//--- Q: Maximum Depth of Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: bottom up recursive solution
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return postorder(root);
    }
    int postorder(TreeNode *root)
    {
    	int lv = 0, rv = 0, val;
    	if (root->left)
    		lv = postorder(root->left);
    	if (root->right)
    		rv = postorder(root->right);
    	return max(lv, rv) + 1;
    }
};