//--- Q: 979. Distribute Coins in Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int res = 0, coins = 0;
        dfs(root, res, coins);
        return res;
    }
    void dfs(TreeNode *root, int &res, int &coins)
    {
    	int coins_l = 0, coins_r = 0;
    	if (root->left)
    		dfs(root->left, res, coins_l);
    	if (root->right)
    		dfs(root->right, res, coins_r);
    	coins = coins_l + coins_r + (root->val-1);
    	res += abs(coins);
    }
};