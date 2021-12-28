//--- Q: 0938. Range Sum of BST

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
    int res = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        preorder(root, low, high);
        return res;
    }
    void preorder(TreeNode *root, int low, int high) {
        if (!root) {
            return;
        }
        while (root) {
            if (root->val < low) {
                root = root->right;
            } else if (root->val > high) {
                root = root->left;
            } else {
                break;
            }
        }
        if (root) {
            res += root->val;
            preorder(root->left, low, high);
            preorder(root->right, low, high);
        }
    }
};

//--- method 2: morris traversal
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        auto now = root;
        int res = 0;
        while (now) {
            if (now->left) {
                auto prev = now;
                now = now->left;
                while (now->right && now->right != prev) {
                    now = now->right;
                }
                if (now->right) {
                    if (prev->val >= low && prev->val <= high) {
                        res += prev->val;
                    }
                    now->right = nullptr;
                    now = prev->right;
                } else {
                    now->right = prev;
                    now = prev->left;
                }
            } else {
                if (now->val >= low && now->val <= high) {
                    res += now->val;
                }
                now = now->right;
            }
        }
        return res;
    }
};