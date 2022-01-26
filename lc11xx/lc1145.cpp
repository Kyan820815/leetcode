//--- Q: 1145. Binary Tree Coloring Game

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs
class Solution {
public:
    int belowlc = 0, belowrc = 0;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        postorder(root, x);
        return max(n-belowlc-belowrc-1, max(belowlc, belowrc)) > n/2;
    }
    int postorder(TreeNode *root, int x) {
        int lc = 0, rc = 0;
        if (root->left) {
            lc = postorder(root->left, x);
        }
        if (root->right) {
            rc = postorder(root->right, x);
        }
        if (root->val == x) {
            belowlc = lc;
            belowrc = rc;
        }
        return lc+rc+1;
    }
};