//--- Q: 545. Boundary of Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: postorder recursion with path recoding
class Solution {
public:
    vector<int> res;
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (root) {
            res.push_back(root->val);
            dfs(root->left, true, false);
            dfs(root->right, false, true);
        }
        return res;
    }
    void dfs(TreeNode *root, bool left, bool right) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            res.push_back(root->val);
            return;
        }
        if (left) {
            res.push_back(root->val);
        }
        dfs(root->left, left, right&&!root->right);
        dfs(root->right, left&&!root->left, right);
        if (right) {
            res.push_back(root->val);
        }
    }
};