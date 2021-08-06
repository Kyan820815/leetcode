//--- Q: 0617. Merge Two Binary Trees

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs, clean code, better
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) {
            return deepcopy(root2);
        } else if (!root2) {
            return deepcopy(root1);
        } else {
            auto now = new TreeNode(root1->val+root2->val);
            now->left = mergeTrees(root1->left, root2->left);
            now->right = mergeTrees(root1->right, root2->right);
            return now;
        }
    }
    TreeNode *deepcopy(TreeNode *root) {
        if (!root) {
            return nullptr;
        }
        auto now = new TreeNode(root->val);
        now->left = deepcopy(root->left);
        now->right = deepcopy(root->right);
        return now;
    }
};