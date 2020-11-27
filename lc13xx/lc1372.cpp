//--- Q: 1372. Longest ZigZag Path in a Binary Tree

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
    int longestZigZag(TreeNode* root) {
        int res = 0;
        postorder(root, -1, res);
        return res;
    }
    int postorder(TreeNode *root, int dir, int &res) {
        int lv = 0, rv = 0, now = 0;
        if (root->left) {
            lv = postorder(root->left, 0, res);
        }
        if (root->right) {
            rv = postorder(root->right, 1, res);
        }
        if (dir == 1) {
            now = 1 + lv;
        } else if (dir == 0) {
            now = 1 + rv;
        }
        res = max(res, now);
        return now;
    }
};