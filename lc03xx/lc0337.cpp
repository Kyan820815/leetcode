//--- Q: 337. House Robber III

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dp recursion
class Solution {
public:
	int rob(TreeNode* root) {
		unordered_map<TreeNode *,int> dp;
		return dfs(root, dp);
	}
	int dfs(TreeNode *root, unordered_map<TreeNode *,int> &dp)
	{
		int ll, lr, rl, rr;
		if (!root) return 0;
		if (dp.count(root))
			return dp[root];
		ll = lr = rl = rr = 0;
		if (root->left)
		{
			ll = dfs(root->left->left, dp);
			lr = dfs(root->left->right, dp);
		}
		if (root->right)
		{
			rl = dfs(root->right->left, dp);
			rr = dfs(root->right->right, dp);
		}

		dp[root] = max(root->val + ll + lr + rl + rr, dfs(root->left, dp) + dfs(root->right, dp));
		return dp[root];
	}
};

//--- method 2: dp recursion with res vector
class Solution {
public:
	int rob(TreeNode* root) {
		vector<int> res;
		res = dfs(root);
		return max(res[0], res[1]);
	}
	vector<int> dfs(TreeNode *root)
	{
		vector<int> left(2,0), right(2,0), res(2,0);
		if (!root) return res;
		if (root->left)
			left = dfs(root->left);
		if (root->right)
			right = dfs(root->right);

		res[0] = max(left[0],left[1]) + max(right[0]+right[1]);
		res[1] = left[0] + right[0] + root->val;
		return res;
	}
};

//--- method 3: dfs recursion, no vector, better
class Solution {
public:
	int rob(TreeNode* root) {
		int l = 0, r = 0;
		if (!root) return 0;
		return dfs(root, l, r);
	}
	int dfs(TreeNode *root, int &l, int &r)
	{
		int ll, lr, rl, rr;
		ll = lr = rl = rr = 0;
		if (root->left)
			l = dfs(root->left, ll, lr);
		if (root->right)
			r = dfs(root->right, rl, rr);
		return max(root->val + ll + lr + rl + rr, l + r);
	}
}; 