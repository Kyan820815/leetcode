//--- Q: 0993. Cousins in Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: preorder
class Solution {
public:
    int xd, yd, xp, yp;
    bool isCousins(TreeNode* root, int x, int y) {
        preorder(root, x, y, 0, -1);
        return xd == yd && xp != yp;
    }
    void preorder(TreeNode *root, int x, int y, int d, int p) {
        if (root->val == x) {
            xp = p;
            xd = d;
        }
        if (root->val == y) {
            yp = p;
            yd = d;
        }
        if (root->left) {
            preorder(root->left, x, y, d+1, root->val);
        }
        if (root->right) {
            preorder(root->right, x, y, d+1, root->val);
        }
    }
};