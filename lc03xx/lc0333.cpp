//--- Q: 333. Largest BST Subtree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: postorder with min value and max value
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int minv = INT_MIN, maxv = INT_MAX;
        if (!root)
            return 0;
        return postorder(root, minv, maxv);
    }
    int postorder(TreeNode *root, int &minv, int &maxv) {
        int lcnt = 0, rcnt = 0;
        int lmaxv = INT_MAX, lminv = INT_MIN;
        int rmaxv = INT_MAX, rminv = INT_MIN;
        
        if (root->left)
            lcnt = postorder(root->left, lminv, lmaxv);
        if (root->right)
            rcnt = postorder(root->right, rminv, rmaxv);
        
        if (root->left && root->val <= lmaxv || root->right && root->val >= rminv) {
            return max(lcnt, rcnt);
        } else {
            minv = (root->left) ? lminv : root->val;
            maxv = (root->right) ? rmaxv : root->val;
            return 1 + lcnt + rcnt;
        }
    }
};