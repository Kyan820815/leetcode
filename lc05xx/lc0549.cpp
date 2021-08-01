//--- Q: 0549. Binary Tree Longest Consecutive Sequence II

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
        int len = 0;
        postorder(root, len, -1);
        return res;
    }
    int postorder(TreeNode *root, int &len, int p) {
        int lv = 0, rv = 0, ld = 0, rd = 0;
        if (root->left) {
            ld = postorder(root->left, lv, root->val);
        }
        if (root->right) {
            rd = postorder(root->right, rv, root->val);
        }
        if (ld+rd == 0) {
            res = max(res, lv+rv+1);
        } else {
            res = max(res, max(lv,rv)+1);
        }
        auto diff = p-root->val;
        if (abs(diff) == 1) {
            len = 1;
            if (ld == diff && rd == diff) {
                len += max(lv, rv);
            } else if (ld == diff) {
                len += lv;
            } else if (rd == diff) {
                len += rv;
            }
        }
        return diff;
    }
};