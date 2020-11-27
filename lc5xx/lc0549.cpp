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
    int longestConsecutive(TreeNode* root) {
        res = 0;
        int dif = 0;
        if (root) {
            postorder(root, root->val, dif);
        }
        return res;
    }
    int postorder(TreeNode *root, int parent, int &dif) {
        int lv = 0, rv = 0, ldif = 0, rdif = 0;
        if (root->left) {
            lv = postorder(root->left, root->val, ldif);
        }
        if (root->right) {
            rv = postorder(root->right, root->val, rdif);
        }
		// this [child - parent - child] can be counted if left diff + right diff = 0
        if (ldif + rdif == 0) {
            res = max(res, lv + rv + 1);
        } else {
            res = max(res, max(lv, rv) + 1);
        }
        dif = parent - root->val;
        if (dif == 1 || dif == -1) {
            if (ldif == dif && rdif == dif) {
                return max(lv, rv) + 1;
            } else if (ldif == dif) {
                return lv + 1;
            } else if (rdif == dif) {
                return rv + 1;
            } else {
                return 1;
            }
        }
        return 0;
    }
    int res;
};