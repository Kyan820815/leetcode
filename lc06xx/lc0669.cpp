//--- Q: 0669. Trim a Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs to find appropriate node using bst nature
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        while (root) {
            if (root->val < low) {
                root = root->right;
            } else if (root->val > high) {
                root = root->left;
            } else {
                root->left = trimBST(root->left, low, high);
                root->right = trimBST(root->right, low, high);
                return root;
            }
        }
        return nullptr;
    }
};

//--- method 2: trim iteration O(1) space
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        while (root) {
            if (root->val < low) {
                root = root->right;
            } else if (root->val > high) {
                root = root->left;
            } else {
                break;
            }
        }
        auto now = root;
        while (now) {
            if (now->left && now->left->val < low) {
                now->left = now->left->right;
            } else {
                now = now->left;
            }
        }
        now = root;
        while (now) {
            if (now->right && now->right->val > high) {
                now->right = now->right->left;
            } else {
                now = now->right;
            }
        }
        return root;
    }
};