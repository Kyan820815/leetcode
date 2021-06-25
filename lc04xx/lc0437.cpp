//--- Q: 437. Path Sum III

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: prefix sum with dfs
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int,int> map;
        int val = 0, res = 0;
        if (!root) return 0;
        map[0] = 1;
        dfs(root, map, sum, val, res);
        return res;
    }
    void dfs(TreeNode *root, unordered_map<int,int> &map, int sum, int val, int &res)
    {
    	val += root->val;
    	res += map[val-sum];
    	++map[val];
    	if (root->left)
    		dfs(root->left, map, sum, val, res);
    	if (root->right)
    		dfs(root->right, map, sum, val, res);
        --map[val];
    }
};

//--- method 2: double dfs
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
    	if (!root) return 0;
        return sumroot(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int sumroot(TreeNode *root, int pre, int sum)
    {
    	if (!root) return 0;
    	pre += root->val;
    	return (pre == sum) + sumroot(root->left, pre, sum) + sumroot(root->right, pre, sum);
    }
};