//--- Q: 1022. Sum of Root To Leaf Binary Numbers

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs
class Solution {
public:
    int res = 0;
    int sumRootToLeaf(TreeNode* root) {
        preorder(root, 0);
        return res;
    }
    void preorder(TreeNode *root, int sum) {
        sum = (sum<<1)+root->val;
        if (!root->left && !root->right) {
            res += sum;
        }
        if (root->left) {
            preorder(root->left, sum);
        }
        if (root->right) {
            preorder(root->right, sum);
        }
    }
};