//--- Q: 0298. Binary Tree Longest Consecutive Sequence

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

//--- method 1-1: postorder
class Solution {
public:
    int res = 0;
    int longestConsecutive(TreeNode* root) {
        int len = 0;
        postorder(root, -1, len);
        return res;
    }
    int postorder(TreeNode *root, int p, int &len) {
        int lv = 0, rv = 0, lb = 1, rb = 1;
        if (root->left) {
            lb = postorder(root->left, root->val, lv);
        }
        if (root->right) {
            rb = postorder(root->right, root->val, rv);
        }
        res = max(res, max(lv, rv)+1);
        int diff = p-root->val == -1;
        if (diff) {
            if (lb && rb) {
                len = max(lv,rv)+1;
            } else if (lb) {
                len = lv+1;
            } else if (rb) {
                len = rv+1;
            } else {
                len = 1;
            }
        }
        return diff;
    }
};