//--- Q: 0222. Count Complete Tree Nodes

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs with counting complete tree
class Solution {
public:
    int countNodes(TreeNode* root) {
        int left = 0, right = 0;
        auto now = root;
        while (now) {
            ++left;
            now = now->left;
        }
        now = root;
        while (now) {
            ++right;
            now = now->right;
        }
        return left == right ? pow(2,left)-1 : 1 + countNodes(root->left) + countNodes(root->right);
    }
};