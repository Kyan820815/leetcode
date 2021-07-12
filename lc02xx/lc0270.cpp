//--- Q: 0270. Closest Binary Search Tree Value

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: binary search with bst attribute
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        double diff = 10001, res;
        while (root) {
            if (diff > abs(target-root->val)) {
                diff = abs(target-root->val);
                res = root->val;
            }
            if (root->val < target) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return res;
    }
};