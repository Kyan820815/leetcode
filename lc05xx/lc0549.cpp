//--- Q: 549. Binary Tree Longest Consecutive Sequence II

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
    int longestConsecutive(TreeNode* root) {
        int v = 0;
        if (root) {
            postorder(root, v, -1);
        }
        return res;
    }
    int postorder(TreeNode *root, int &v, int p) {
        int lv = 0, rv = 0;
        int ldiff = 0, rdiff = 0;
        if (root->left) {
            ldiff = postorder(root->left, lv, root->val);
        }
        if (root->right) {
            rdiff = postorder(root->right, rv, root->val);
        }
        if (ldiff + rdiff == 0) {
            res = max(res, lv+rv+1);
        } else {
            res = max(res, max(lv, rv)+1);
        }
        int diff = p-root->val;
        if (abs(diff) == 1) {
            v = 1;
            if (diff == ldiff && diff == rdiff) {
                v = max(lv, rv) + 1;
            } else if (diff == ldiff) {
                v = lv + 1;
            } else if (diff == rdiff) {
                v = rv+1;
            }
            return diff;
        }
        return 0;
    }
};