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
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        if (root) {
            postorder(root, res, root->val);
            return res - 1;
        }
        return 0;
    }
    int postorder(TreeNode *root, int &res, int parent) {
        int lv = 0, rv = 0;
        if (root->left) {
            lv = postorder(root->left, res, root->val);
        }
        if (root->right) {
            rv = postorder(root->right, res, root->val);
        }
        res = max(res, lv + rv + 1);
        return parent == root->val ? max(lv, rv) + 1 : 0;
    }
};