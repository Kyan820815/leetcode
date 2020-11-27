//--- Q: 563. Binary Tree Tilt

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: record sum and tilt every step, postorder
class Solution {
public:
    int findTilt(TreeNode* root) {
    	if (!root) return 0;
    	int res = 0;
        postorder(root, res);
        return res;
    }
    int postorder(TreeNode *root, int &res)
    {
    	int left_sum = 0, right_sum = 0;
    	if (root->left)
    		left_sum = postorder(root->left, res);
    	if (root->right)
    		right_sum = postorder(root->right, res);
    	res += abs(left_sum-right_sum);
    	return left_sum+right_sum+root->val;
    }
};