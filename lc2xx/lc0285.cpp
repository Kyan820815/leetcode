//--- Q: 285. Inorder Successor in BST

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: inorder recursion
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *last = NULL, *res = NULL;
        inorder(root, p, &res, &last);
        return res;
    }
    void inorder(TreeNode *root, TreeNode *p, TreeNode **res, TreeNode **last) {
        if (root->left)
            inorder(root->left, p, res, last);
        if (*last == p) {
            *res = root;
            *last = NULL;
            return;
        }
        *last = root;
        if (root->right)
            inorder(root->right, p, res, last);
    }
};

//--- method 2: stack iteration
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode *> sk;
        TreeNode *now = root, *last = NULL;
        while (sk.size() || now) {
            while (now) {
                sk.push(now);
                now = now->left;
            }
            if (!now && sk.size()) {
                now = sk.top();
                sk.pop();
                if (last == p)
                    return now;
                last = now;
                now = now->right;
            }
        }
        return NULL;
    }
};

//--- method 3: bst traversal
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *now = root, *res = NULL;
        while (now) {
            if (now->val <= p->val)
                now = now->right;
            else {
                res = now;
                now = now->left;
            }
        }
        return res;
    }
};