//--- Q: 0250. Count Univalue Subtrees

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: postorder with compare parent and child node。
class Solution {
public:
    int res = 0;
    int countUnivalSubtrees(TreeNode* root) {
        if (root) {
            postorder(root, -1001);
        }
        return res;
    }
    int postorder(TreeNode *root, int p) {
        int lb = 1, rb = 1;
        if (root->left) {
            lb = postorder(root->left, root->val);
        }
        if (root->right) {
            rb = postorder(root->right, root->val);
        }
        if (lb && rb) {
            ++res;
        } else {
            return false;
        }
        return p == root->val;
    }
};
