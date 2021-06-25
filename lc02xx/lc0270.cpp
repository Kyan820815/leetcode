//--- Q: 270. Closest Binary Search Tree Value

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: preorder with bst attribute
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        double diff = DBL_MAX;
        int res;
        preorder(root, target, diff, res);
        return res;
    }
    void preorder(TreeNode *root, double target, double &diff, int &res) {
        if (diff > abs(target-root->val)) {
            diff = abs(target-root->val);
            res = root->val;
        }
        if (root->val > target && root->left)
            preorder(root->left, target, diff, res);
        else if (root->val < target && root->right)
            preorder(root->right, target, diff, res);
    }
};