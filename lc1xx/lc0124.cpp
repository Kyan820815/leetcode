//--- Q: 124. Binary Tree Maximum Path Sum

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
    int maxPathSum(TreeNode* root) {
		int maxv = INT_MIN;        
		postorder(root, maxv);
		return maxv;
    }
    int postorder(TreeNode *root, int &maxv)
    {
    	int leftv = 0, rightv = 0, now;
    	if (root->left)
    		leftv = postorder(root->left, maxv);
    	if (root->right)
    		rightv = postorder(root->right, maxv);
    	now = root->val;
    	now = max(now, root->val + max(leftv,rightv));
    	maxv = max(maxv, now);
    	maxv = max(maxv, root->val+leftv+rightv);
    	return now;
    }
};