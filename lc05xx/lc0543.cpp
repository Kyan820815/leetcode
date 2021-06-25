//--- Q: 543. Diameter of Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: postorder
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
    	int res = INT_MIN;
        int h = postorder(root, res);
        return res==INT_MIN ? 0 : res;
    }
    int postorder(TreeNode *root, int &res)
    {
    	int lh = 0, rh = 0;
    	if (!root) return 0;
    	if (root->left)
    		lh = postorder(root->left, res);
    	if (root->right)
    		rh = postorder(root->right, res);
    	res = max(res, lh+rh);
    	return max(lh, rh) + 1;
    }
};