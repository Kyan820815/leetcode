//--- Q: 0257. Binary Tree Paths

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
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        preorder(root, "");
        return res;
    }
    void preorder(TreeNode *root, string path) {
        path += to_string(root->val);
        if (!root->left && !root->right) {
            res.push_back(path);
            return;
        }
        path += "->";
        if (root->left) {
            preorder(root->left, path);
        }
        if (root->right) {
            preorder(root->right, path);
        }
    }
};