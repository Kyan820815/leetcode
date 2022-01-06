//--- Q: 0965. Univalued Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: postorder recursion
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        return postorder(root, root->val);
    }
    bool postorder(TreeNode *root, int p) {
        if (!root) {
            return true;
        }
        auto lv = postorder(root->left, root->val);
        auto rv = postorder(root->right, root->val);
        if (!lv || !rv || root->val != p) {
            return false;
        }
        return true;
    }
};