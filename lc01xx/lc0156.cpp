//--- Q: 0156. Binary Tree Upside Down

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: postorder without last pointer
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        TreeNode *nr = nullptr;
        dfs(root, &nr);
        return nr;
    }
    TreeNode *dfs(TreeNode *root, TreeNode **nr) {
        TreeNode *left_child = nullptr, *new_root = nullptr;
        if (root->left) {
            new_root = dfs(root->left, nr);
        }
        if (root->right) {
            left_child = dfs(root->right, nr);
        }
        if (!(*nr)) {
            *nr = root;
        } else if (new_root) {
            new_root->left = left_child;
            new_root->right = root;
        }
        root->left = root->right = nullptr;
        return root;
    }
};