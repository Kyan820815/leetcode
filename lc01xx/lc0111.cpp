//--- Q: 0111. Minimum Depth of Binary Tree
//--- last written: 2023/07/13

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: choose path method
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (!root->left) {
            return minDepth(root->right)+1;
        }
        if (!root->right) {
            return minDepth(root->left)+1;
        }
        return min(minDepth(root->left), minDepth(root->right))+1;
    }
};

//--- method 2: preorder
class Solution {
public:
    int res = INT_MAX;
    int minDepth(TreeNode* root) {
        if (root) {
            preorder(root, 1);
        }
        return res == INT_MAX ? 0 : res;
    }
    void preorder(TreeNode *root, int h) {
        if (!root->left && !root->right) {
            res = min(res, h);
        }
        if (root->left) {
            preorder(root->left, h+1);
        }
        if (root->right) {
            preorder(root->right, h+1);
        }
    }
};
