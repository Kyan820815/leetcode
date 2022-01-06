//--- Q: 0979. Distribute Coins in Binary Tree

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
    int distributeCoins(TreeNode* root) {
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
        int sum = root->val+lv+rv-1;
        res += abs(sum);
        return sum;
    }
};