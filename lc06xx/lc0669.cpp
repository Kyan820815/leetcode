//--- Q: 669. Trim a Binary Search Tree

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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return root;
        if (root->val < L)
            return trimBST(root->right, L, R);
        else if (root->val > R)
            return trimBST(root->left, L, R);
        else
        {
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            return root;
        }
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