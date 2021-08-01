//--- Q: 0563. Binary Tree Tilt

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: record sum and tilt every step, postorder
class Solution {
public:
    int res = 0;
    int findTilt(TreeNode* root) {
        if (root) {
            postorder(root);
        }
        return res;
    }
    int postorder(TreeNode *root) {
        int lv = 0, rv = 0;
        if (root->left) {
            lv = postorder(root->left);
        }
        if (root->right) {
            rv = postorder(root->right);
        }
        res += abs(lv-rv);
        return lv+rv+root->val;
    }
};