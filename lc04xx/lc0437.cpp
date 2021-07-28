//--- Q: 0437. Path Sum III

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
    unordered_map<int, int> map;
    int res = 0;
    int pathSum(TreeNode* root, int targetSum) {
        map[0] = 1;
        if (root) {
            preorder(root, targetSum, 0);
        }
        return res;
    }
    void preorder(TreeNode *root, int targetSum, int sum) {
        sum += root->val;
        res += map[sum-targetSum];
        ++map[sum];
        if (root->left) {
            preorder(root->left, targetSum, sum);
        }
        if (root->right) {
            preorder(root->right, targetSum, sum);
        }
        --map[sum];
    }
};