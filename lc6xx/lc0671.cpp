//--- Q: 671. Second Minimum Node In a Binary Tree

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
    int findSecondMinimumValue(TreeNode* root) {
        int now = 0;
        if (root) {
            now = postorder(root, root->val);
        }
        return now != 0 ? now : -1;
    }
    int postorder(TreeNode *root, int val) {
        if (root->val != val) {
            return root->val;
        }
        int lv = 0, rv = 0;
        if (root->left) {
            lv = postorder(root->left, val);
        }
        if (root->right) {
            rv = postorder(root->right, val);
        }
        if (!lv) {
            return rv;
        } else if (!rv) {
            return lv;
        }
        return min(lv, rv);
    }
};