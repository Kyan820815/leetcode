//--- Q: 1448. Count Good Nodes in Binary Tree

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

//--- method 1: dfs
class Solution {
public:
    int goodNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return dfs(root, INT_MIN);      
    }
    int dfs(TreeNode *root, int maxv) {
        int lv = 0, rv = 0;
        maxv = max(maxv, root->val);
        if (root->left) {
            lv = dfs(root->left, maxv);
        }
        if (root->right) {
            rv = dfs(root->right, maxv);
        }
        return lv + rv + ((maxv <= root->val) ? 1 : 0);
    }
};

//--- method 2: preorder
class Solution {
public:
    int res = 0;
    int goodNodes(TreeNode* root) {
        preorder(root, INT_MIN);
        return res;
    }
    void preorder(TreeNode *root, int v) {
        if (root->val >= v) {
            ++res;
            v = root->val;
        }
        if (root->left) {
            preorder(root->left, v);
        }
        if (root->right) {
            preorder(root->right, v);
        }
    }
};