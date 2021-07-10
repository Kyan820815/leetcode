//--- Q: 0230. Kth Smallest Element in a BST

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

//--- method 1: morris traversal
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int val;
        while (root) {
            if (root->left) {
                auto prev = root;
                root = root->left;
                while (root->right && root->right != prev) {
                    root = root->right;
                }
                if (root->right) {
                    root->right = nullptr;
                    root = prev->right;
                    if (!--k) {
                        val = prev->val;
                    }
                } else {
                    root->right = prev;
                    root = prev->left;
                }
            } else {
                if (!--k) {
                    val = root->val;
                }
                root = root->right;
            }
        }
        return val;
    }
};