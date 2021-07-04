//--- Q: 0114. Flatten Binary Tree to Linked List

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: iteration
class Solution {
public:
    void flatten(TreeNode* root) {
        while (root) {
            if (root->left) {
                auto prev = root;
                root = root->left;
                auto tmp = root;
                while (root->right) {
                    root = root->right;
                }
                root->right = prev->right;
                prev->right = tmp;
                prev->left = NULL;
                root = prev;
            }
            root = root->right;
        }
    }
};