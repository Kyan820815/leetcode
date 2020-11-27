//--- Q: 1022. Sum of Root To Leaf Binary Numbers

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
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        dfs(root, res, 0);
        return res;
    }
    void dfs(TreeNode *root, int &res, int sum)
    {
        if (!root) return;
        sum = (sum << 1) + root->val;
        dfs(root->left, res, sum);
        dfs(root->right, res, sum);
        if (!root->left && !root->right)
            res += sum;
    }
};