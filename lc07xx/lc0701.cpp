//--- Q: 0701. Insert into a Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};

//--- method 2: iteration, O(1) space
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *dummy = new TreeNode(INT_MAX, root, nullptr), *now = dummy, *parent = nullptr;
        int dir;
        while (now) {
            parent = now;
            if (now->val > val) {
                dir = 0;
                now = now->left;
            } else {
                dir = 1;
                now = now->right;
            }
        }
        auto new_node = new TreeNode(val);
        if (!dir) {
            parent->left = new_node;
        } else {
            parent->right = new_node;
        }
        return dummy->left;
    }
};