//--- Q: 0098. Validate Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dynamically allocate min and max of current node, better
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return preorder(root, LONG_MIN, LONG_MAX);
    }
    bool preorder(TreeNode *root, long long minv, long long maxv) {
        if (!root) {
            return true;
        }
        if (root->val <= minv || root->val >= maxv) {
            return false;
        }
        return preorder(root->left, minv, root->val) && preorder(root->right, root->val, maxv);
    }
};

//--- method 2: inorder traversal
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *now = root, *last = NULL;
        bool find = true;
        while (now) {
            if (now->left) {
                auto prev = now;
                now = now->left;
                while (now->right && now->right != prev) {
                    now = now->right;
                }
                if (!now->right) {
                    now->right = prev;
                    now = prev->left;
                } else {
                    if (last && last->val >= prev->val) {
                        find = false;
                    }
                    now->right = NULL;
                    last = prev;
                    now = prev->right;
                }
            } else {
                if (last && last->val >= now->val) {
                    find = false;
                }
                last = now;
                now = now->right;
            }
        }
        return find;
    }
};