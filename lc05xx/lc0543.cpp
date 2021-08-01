//--- Q: 0543. Diameter of Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: postorder
class Solution {
public:
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        postorder(root);
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
        res = max(res, lv+rv);
        return max(lv, rv)+1;
    }
};