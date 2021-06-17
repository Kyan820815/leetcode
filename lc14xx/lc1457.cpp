//--- Q: 1457. Pseudo-Palindromic Paths in a Binary Tree

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


//--- method 1: xor
class Solution {
public:
    int res = 0, cnt = 0;
    int pseudoPalindromicPaths (TreeNode* root) {
        preorder(root);
        return res;
    }
    void preorder(TreeNode *root) {
        bool erase = false;
        cnt ^= (1 << root->val);
        if (!root->left && !root->right) {
            if ((cnt & (cnt-1)) == 0) {
                ++res;
            }
        }
        if (root->left) {
            preorder(root->left);
        }
        if (root->right) {
            preorder(root->righ);
        }
        cnt ^= (1 << root->val);
    }
};

//--- method 2: set
class Solution {
public:
    int res = 0;
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_set<int> set;
        preorder(root, set);
        return res;
    }
    void preorder(TreeNode *root, unordered_set<int> &set) {
        bool erase = false;
        if (set.find(root->val) == set.end()) {
            set.insert(root->val);
        } else {
            erase = true;
            set.erase(root->val);
        }
        if (!root->left && !root->right) {
            if (set.size() <= 1) {
                ++res;
            }
        }
        if (root->left) {
            preorder(root->left, set);
        }
        if (root->right) {
            preorder(root->right, set);
        }
        if (erase) {
            set.insert(root->val);
        } else {
            set.erase(root->val);
        }
    }
};