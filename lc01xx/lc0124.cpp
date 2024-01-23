//--- Q: 0124. Binary Tree Maximum Path Sum
//--- last written: 2023/07/14

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
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        postorder(root);
        return res;
    }
    int postorder(TreeNode *root) {
        int lv = 0, rv = 0;
        if (root->left) {
            lv = max(0, postorder(root->left));
        }
        if (root->right) {
            rv = max(0, postorder(root->right));
        }
        res = max(res, root->val+lv+rv);
        return root->val+max(lv, rv);
    }
};
