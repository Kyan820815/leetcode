//--- Q: 298. Binary Tree Longest Consecutive Sequence

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
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        if (root) {
            postorder(root, root->val, res);
            return res + 1;
        }
        return 0;
    }
    int postorder(TreeNode *root, int p, int &res) {
        int lv = 0, rv = 0;
        if (root->left) {
            lv = postorder(root->left, root->val, res);
        }
        if (root->right) {
            rv = postorder(root->right, root->val, res);
        }
        int now;
        if (root->val - 1 == p) {
            now = max(lv, rv) + 1;
            res = max(now, res);
        } else {
            now = 0;
        }
        return now;
    }
};

//--- method 1-2: another view of postorder
class Solution {
public:
    int res = 0;
    int longestConsecutive(TreeNode* root) {
        int len = 0;
        postorder(root, -1, len);
        return res;
    }
    bool postorder(TreeNode *root, int p, int &len) {
        int llen = 0, rlen = 0;
        bool lv = true, rv = true;
        if (root->left) {
            lv = postorder(root->left, root->val, llen);
        }
        if (root->right) {
            rv = postorder(root->right, root->val, rlen);
        }
        llen = lv ? llen : 0;
        rlen = rv ? rlen : 0;
        len = max(llen, rlen) + 1;
        res = max(res, len);
        return root->val-p == 1;
    }
};