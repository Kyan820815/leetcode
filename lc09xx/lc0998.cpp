//--- Q: 998. Maximum Binary Tree II

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: 
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode *nr;
        if (!root) return new TreeNode(val);
        if (root->val < val)
        {
            nr = new TreeNode(val);
            nr->left = root;
            return nr;
        }
        else
            root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};