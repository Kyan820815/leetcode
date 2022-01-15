//--- Q: 1008. Construct Binary Search Tree from Preorder Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: stack iteration
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<TreeNode *> sk;
        TreeNode *root = nullptr;
        for (auto &val: preorder) {
            TreeNode *now = new TreeNode(val), *last = nullptr;
            while (sk.size() && sk.back()->val < val) {
                last = sk.back();
                sk.pop_back();
            }
            if (last) {
                last->right = now;
            } else if (sk.size()) {
                sk.back()->left = now;
            }
            if (!root) {
                root = now;
            }
            sk.push_back(now);
        }
        return root;
    }
};

//--- method 2: dfs recursion
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *dummy = new TreeNode(-1);
        for (auto &val: preorder) {
            dfs(dummy, val);
        }
        return dummy->left;
    }
    void dfs(TreeNode *dummy, int val) {
        TreeNode *parent = dummy, *root = dummy->left;
        int dir = 0;
        while (root) {
            if (root->val < val) {
                parent = root;
                dir = 1;
                root = root->right;
            } else {
                parent = root;
                dir = 0;
                root = root->left;
            }
        }
        if (dir) {
            parent->right = new TreeNode(val);
        } else {
            parent->left = new TreeNode(val);
        }
    }
};