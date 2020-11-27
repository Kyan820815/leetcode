//--- Q: 129. Sum Root to Leaf Numbers

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs recursion
class Solution {
public:
    int sumNumbers(TreeNode* root) {
    	int sum = 0;
    	if (!root) return sum;
        dfs(root, sum, 0);
        return sum;
    }
    void dfs(TreeNode *root, int &sum, int now)
    {
    	now = now * 10;
    	now += root->val;
    	if (!root->left && !root->right)
    	{
    		sum += now;
    		return;
    	}
    	if (root->left)
    		dfs(root->left, sum ,now);
    	if (root->right)
    		dfs(root->right, sum, now);
    }
};