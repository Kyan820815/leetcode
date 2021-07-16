//--- Q: 0333. Largest BST Subtree

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
        if (root) {
            return postorder(root, minv, maxv);
        }
        return 0;
    }
    int postorder(TreeNode *root, int &minv, int &maxv) {
        int lminv, lmaxv, rminv, rmaxv, lv, rv;
        lminv = rminv = INT_MIN, lmaxv = rmaxv = INT_MAX;
        lv = rv = 0;
        if (root->left) {
            lv = postorder(root->left, lminv, lmaxv);
        }
        if (root->right) {
            rv = postorder(root->right, rminv, rmaxv);
        }
        if (root->left && lmaxv >= root->val || root->right && rminv <= root->val) {
            return max(lv, rv);
        }
        minv = root->left ? lminv : root->val;
        maxv = root->right ? rmaxv : root->val;
        return lv+rv+1;
    }
};