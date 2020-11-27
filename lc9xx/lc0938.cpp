//--- Q: 938. Range Sum of BST

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: inorder recursion
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int res = 0;
        if (root->val >= L && root->val <= R) {
            res += root->val;
            if (root->left)
                res += rangeSumBST(root->left, L, R);
            if (root->right)
                res += rangeSumBST(root->right, L, R);
        } else if (root->left && root->val > R)
            res += rangeSumBST(root->left, L, R);
        else if (root->right && root->val < L)
            res += rangeSumBST(root->right, L, R);
        return res;
    }
};