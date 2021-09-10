//--- Q: 0776. Split BST

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//--- method 1: binary search
class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        if (!root) {
            return {nullptr, nullptr};
        }
        vector<TreeNode *> res;
        if (root->val > target) {
            res = splitBST(root->left, target);
            root->left = res[1];
            res[1] = root;
        } else {
            res = splitBST(root->right, target);
            root->right = res[0];
            res[0] = root;
        }
        return res;
    }
};