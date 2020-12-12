//--- Q: 1469. Find All The Lonely Nodes

//--- method 1: use tag to check if current node is lonely
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
class Solution {
public:
    vector<int> res;
    vector<int> getLonelyNodes(TreeNode* root) {
        preorder(root, false);
        return res;
    }
    void preorder(TreeNode *root, bool lonley) {
        if (!root) {
            return;
        }
        if (lonley) {
            res.push_back(root->val);
        }
        preorder(root->left, !root->right);
        preorder(root->right, !root->left);
    }
};