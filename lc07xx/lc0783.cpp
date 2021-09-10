//--- Q: 0783. Minimum Distance Between BST Nodes

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: inorder traversal
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int last = -1, res = INT_MAX;
        auto now = root;
        while (now) {
            if (now->left) {
                auto prev = now;
                now = now->left;
                while (now->right && now->right != prev) {
                    now = now->right;
                }
                if (now->right) {
                    if (last != -1) {
                        res = min(res, prev->val-last);
                    }
                    now->right = nullptr;
                    last = prev->val;
                    now = prev->right;
                } else {
                    now->right = prev;
                    now = prev->left;
                }
            } else {
                if (last != -1) {
                    res = min(res, now->val-last);
                }
                last = now->val;
                now = now->right;
            }
        }
        return res;
    }
};