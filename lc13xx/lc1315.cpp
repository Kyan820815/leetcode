//--- Q: 1315. Sum of Nodes with Even-Valued Grandparent

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
    int sumEvenGrandparent(TreeNode* root) {
        int res = 0, l = 0, r = 0;
        if (root) {
            dfs(root, l, r, res);
        }
        return res;
    }
    void dfs(TreeNode *root, int &l, int &r, int &res) {
        int ll, lr, rl, rr;
        ll = lr = rl = rr = 0;
        if (root->left) {
            l = root->left->val;
            dfs(root->left, ll, lr, res);
        }
        if (root->right) {
            r = root->right->val;
            dfs(root->right, rl, rr, res);
        }
        if (!(root->val & 1)) {
            res += ll+lr+rl+rr;
        }
    }
};
