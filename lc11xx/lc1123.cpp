//--- Q: 1123. Lowest Common Ancestor of Deepest Leaves

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: one pass lca postorder
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int d = 0;
        return postorder(root, d);
    }
    TreeNode *postorder(TreeNode *root, int &d) {
        int ld = 0, rd = 0;
        if (!root) {
            return root;
        }
        auto left = postorder(root->left, ld);
        auto right = postorder(root->right, rd);
        d = max(ld, rd)+1;
        if (ld == rd) {
            return root;
        } else if (ld > rd) {
            return left;
        } else {
            return right;
        }
    }
};