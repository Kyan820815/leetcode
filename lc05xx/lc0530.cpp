//--- Q: 0530. Minimum Absolute Difference in BST

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: inorder
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX, last = -100000;
        while (root) {
            if (root->left) {
                auto prev = root;
                root = root->left;
                while (root->right && root->right != prev) {
                    root = root->right;
                }
                if (root->right) {
                    res = min(res, prev->val-last);
                    last = prev->val;
                    root->right = nullptr;
                    root = prev->right;
                } else {
                    root->right = prev;
                    root = prev->left;
                }
            } else {
                res = min(res, root->val-last);
                last = root->val;
                root = root->right;
            }
        }
        return res;
    }
};

//--- method 2: preorder
class Solution {
public:
    int res = 10000;
    int getMinimumDifference(TreeNode* root) {
        preorder(root, INT_MIN, INT_MAX);
        return res;
    }
    void preorder(TreeNode *root, int minv, int maxv) {
        if (minv != INT_MIN) {
            res = min(res, root->val-minv);
        }
        if (maxv != INT_MAX) {
            res = min(res, maxv-root->val);
        }
        if (root->left) {
            preorder(root->left, minv, root->val);
        }
        if (root->right) {
            preorder(root->right, root->val, maxv);
        }
    }
};