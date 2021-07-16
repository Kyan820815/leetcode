//--- Q: 0337. House Robber III

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dp recursion
class Solution {
public:
    int rob(TreeNode* root) {
        int lv = 0, rv = 0;
        return postorder(root, lv, rv);
    }
    int postorder(TreeNode *root, int &lv, int &rv) {
        int llv, lrv, rlv, rrv;
        llv = lrv = rlv = rrv = 0;
        if (root->left) {
            lv = postorder(root->left, llv, lrv);
        }
        if (root->right) {
            rv = postorder(root->right, rlv, rrv);
        }
        return max(root->val+llv+lrv+rlv+rrv, lv+rv);
    }
};