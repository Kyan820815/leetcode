//--- Q: 0285. Inorder Successor in BST

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: bst traversal
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *now = root, *res = NULL;
        while (now) {
            if (now->val <= p->val)
                now = now->right;
            else {
                res = now;
                now = now->left;
            }
        }
        return res;
    }
};

//--- follow up
class Solution {
public:
    TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
        TreeNode *res = nullptr;
        while (root) {
            if (root->val >= p->val) {
                root = root->left;
            } else {
                res = root;
                root = root->right;
            }
        }
        return res;
    }
};