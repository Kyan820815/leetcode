//--- Q: 1740. Find Distance in a Binary Tree

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
    int findDistance(TreeNode* root, int p, int q) {
        postorder(root, p, q);
        return res;
    }
    int postorder(TreeNode *root, int p, int q) {
        if (!root) {
            return -1;
        }
        int ldis = postorder(root->left, p, q);
        int rdis = postorder(root->right, p, q);
        if ((root->val == p || root->val == q) && (ldis >= 0 || rdis >= 0)) {
            res = max(ldis,rdis)+1;
        } else if (ldis >= 0 && rdis >= 0) {
            res = ldis+rdis+2;
        }
        if (root->val == p || root->val == q) {
            return 0;
        } else if (ldis >= 0) {
            return ldis+1;
        } else if (rdis >= 0) {
            return rdis+1;
        }
        return -1;        
    }
};