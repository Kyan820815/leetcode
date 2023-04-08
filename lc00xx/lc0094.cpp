//--- Q: 0094. Binary Tree Inorder Traversal
//--- last written: 2023/04/05

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//--- method 1: iterative solution using stack
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<TreeNode *> sk;
        auto now = root;
        while (now || sk.size()) {
            while (now) {
                sk.push_back(now);
                now = now->left;
            }
            now = sk.back();
            sk.pop_back();
            res.push_back(now->val);
            now = now->right;
        }
        return res;
    }
};

//--- method 2: inorder recursion
class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if (root) {
            inorder(root);
        }
        return res;
    }
    void inorder(TreeNode *root) {
        if (root->left) {
            inorder(root->left);
        }
        res.push_back(root->val);
        if (root->right) {
            inorder(root->right);
        }
    }
};

//--- method 3: morris travesal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        auto now = root;
        while (now) {
            if (now->left) {
                auto prev = now;
                now = now->left;
                while (now->right && now->right != prev) {
                    now = now->right;
                }
                if (now->right) {
                    res.push_back(prev->val);
                    now->right = NULL;
                    now = prev->right;
                } else {
                    now->right = prev;
                    now = prev->left;
                }
            } else {
                res.push_back(now->val);
                now = now->right;
            }
        }
        return res;
    }
};
