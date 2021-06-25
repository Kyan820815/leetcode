//--- Q: 687. Longest Univalue Path

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//--- method 1: postorder
class Solution {
public:
    int res = 0;
    int longestUnivaluePath(TreeNode* root) {
        int v = 0;
        if (root) {
            postorder(root, v, -1);
        }
        return res;
    }
    void postorder(TreeNode *root, int &v, int p) {
        int lv = 0, rv = 0;
        if (root->left) {
            postorder(root->left, lv, root->val);
        }
        if (root->right) {
            postorder(root->right, rv, root->val);
        }
        if (p == root->val) {
            v = max(lv, rv) + 1;
        }
        res = max(res, lv+rv);
    }
};