//--- Q: 0687. Longest Univalue Path

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
    int longestUnivaluePath(TreeNode* root) {
        if (root) {
            postorder(root, -1);
        }
        return res;
    }
    int postorder(TreeNode *root, int p) {
        int lv = 0, rv = 0;
        if (root->left) {
            lv = postorder(root->left, root->val);
        }
        if (root->right) {
            rv = postorder(root->right, root->val);
        }
        res = max(res, lv+rv);
        int len = root->val == p ? max(lv,rv)+1 : 0;
        return len;
    }
};

//--- follow up:
class Solution {
public:
    int res = 0;
    int longestUnivaluePath(TreeNode* root) {
        if (root) {
            postorder(root, -1);
        }
        return res;
    }
    int postorder(TreeNode *root, int p) {
        int lv = 0, rv = 0;
        if (root->left) {
            lv = postorder(root->left, root->val);
        }
        if (root->right) {
            rv = postorder(root->right, root->val);
        }
        if (root->left && !lv && root->right && !rv) {
            return 0;
        }
        res = max(res, lv+rv);
        int len = root->val == p ? max(lv,rv)+1 : 0;
        return len;
    }
};