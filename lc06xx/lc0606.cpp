//--- Q: 0606. Construct String from Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs and find the law
class Solution {
public:
    string tree2str(TreeNode* root) {
        string str = to_string(root->val);
        if (root->left) {
            str += '(';
            str += tree2str(root->left);
            str += ')';
        }
        if (root->right) {
            str += !root->left ? "()" : "";
            str += '(';
            str += tree2str(root->right);
            str += ')';
        }
        return str;
    }
};