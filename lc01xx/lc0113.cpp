//--- Q: 0113. Path Sum II

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
    vector<int> res;
    vector<vector<int>> res_vec;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root) {
            preorder(root, targetSum);
        }
        return res_vec;
    }
    void preorder(TreeNode *root, int targetSum) {
        res.push_back(root->val);
        if (!root->left && !root->right) {
            if (!(targetSum-root->val)) {
                res_vec.push_back(res);
            }
            res.pop_back();
            return;
        }
        if (root->left) {
            pathSum(root->left, targetSum-root->val);
        }
        if (root->right) {
            pathSum(root->right, targetSum-root->val);
        }
        res.pop_back();
    }
};