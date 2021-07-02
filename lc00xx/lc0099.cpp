//--- Q: 0099. Recover Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: O(1) space, morris traversal
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *now = root, *first = NULL, *second = NULL, *last = NULL;
        while (now) {
            if (now->left) {
                auto prev = now;
                now = prev->left;
                while (now->right && now->right != prev) {
                    now = now->right;
                }
                if (!now->right) {
                    now->right = prev;
                    now = prev->left;
                } else {
                    if (last && last->val >= prev->val) {
                        if (!first) {
                            first = last;
                        }
                        second = prev;
                    }
                    now->right = NULL;
                    last = prev;
                    now = prev->right;
                }
            } else {
                if (last && last->val >= now->val) {
                    if (!first) {
                        first = last;
                    }
                    second = now;
                }
                last = now;
                now = now->right;
            }
        }
        swap(first->val, second->val);
    }
};