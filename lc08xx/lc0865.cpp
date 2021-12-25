//--- Q: 0865. Smallest Subtree with all the Deepest Nodes

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: postorder
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int val = 0;
        return postorder(root, val);
    }
    TreeNode *postorder(TreeNode *root, int &val) {
        if (!root) {
            return root;
        }
        int lv = 0, rv = 0;
        auto left = postorder(root->left, lv);
        auto right = postorder(root->right, rv);
        val = max(lv,rv)+1;
        if (lv == rv) {
            return root;
        } else if (lv > rv) {
            return left;
        } else {
            return right;
        }
    }
};