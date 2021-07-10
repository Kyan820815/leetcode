//--- Q: 0226. Invert Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: postorder traversal
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        auto nright = invertTree(root->left);
        auto nleft = invertTree(root->right);
        root->left = nleft;
        root->right = nright;
        return root;
    }
};