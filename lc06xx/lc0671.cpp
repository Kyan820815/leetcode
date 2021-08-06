//--- Q: 0671. Second Minimum Node In a Binary Tree

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

//--- method 1: preorder
class Solution {
public:
    int find = 0;
    int findSecondMinimumValue(TreeNode* root) {
        int v = preorder(root, root->val);
        return find ? v : -1;
    }
    int preorder(TreeNode *root, int p) {
        if (p != root->val) {
            find = 1;
            return root->val;
        }
        int lv = INT_MAX, rv = INT_MAX;
        if (root->left) {
            lv = preorder(root->left, root->val);
        }
        if (root->right) {
            rv = preorder(root->right, root->val);
        }
        return min(lv, rv);
    }
};