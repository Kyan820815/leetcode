//--- Q: 1120. Maximum Average Subtree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs recursion
class Solution {
public:
    double res = 0;
    double maximumAverageSubtree(TreeNode* root) {
        int sum = 0;
        postorder(root, sum);
        return res;
    }
    int postorder(TreeNode *root, int &sum) {
        int lv = 0, rv = 0, lcnt = 0, rcnt = 0;
        if (root->left) {
            lcnt = postorder(root->left, lv);
        }
        if (root->right) {
            rcnt = postorder(root->right, rv);
        }
        sum = root->val+lv+rv;
        int cnt = lcnt+rcnt+1;
        res = max(res, (double)sum/cnt);
        return cnt;
    }
};