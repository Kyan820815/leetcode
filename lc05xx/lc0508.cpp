//--- Q: 508. Most Frequent Subtree Sum

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
    vector<int> findFrequentTreeSum(TreeNode* root) {
		unordered_map<int, int> map;
		vector<int> out;
		int cnt = 0;
		if (!root) return out;
				
		dfs(root, map, cnt);
		for (auto &a: map)
		{
			if (a.second == cnt)
				out.push_back(a.first);
		}
		return out;
    }
    int dfs(TreeNode *root, unordered_map<int,int> &map, int &cnt)
    {
    	int sum, left_sum = 0, right_sum = 0;
    	if (root->left)
    		left_sum = dfs(root->left, map, cnt);
    	if (root->right)
    		right_sum = dfs(root->right, map, cnt);

    	sum = left_sum + right_sum + root->val;
    	map[sum]++;
    	if (cnt < map[sum])
    		cnt = map[sum];
    	return sum;
    }
};