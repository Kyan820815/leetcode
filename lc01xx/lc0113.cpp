//--- Q: 113. Path Sum II

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> out_vec;
        vector<int> out;
        if (!root) return out_vec;
        dfs(root, sum, 0, out_vec, out);
        return out_vec;
    }
    void dfs(TreeNode *root, int sum, int now_sum, vector<vector<int>> &out_vec, vector<int> &out)
    {
    	now_sum += root->val;
    	out.push_back(root->val);
    	if (!root->left && !root->right)
    	{
    		if (now_sum == sum)
    			out_vec.push_back(out);
    		out.pop_back();
    		return;
    	}
    	if (root->left)
    		dfs(root->left, sum, now_sum, out_vec, out);
    	if (root->right)
    		dfs(root->right, sum, now_sum, out_vec, out);
    	out.pop_back();
    }
};