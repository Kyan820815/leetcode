//--- Q: 0998. Maximum Binary Tree II

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: find suitable position to insert
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        if (root->val < val) {
            auto now = new TreeNode(val);
            now->left = root;
            return now;
        } else {
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        }
    }
};