//--- Q: 0144. Binary Tree Preorder Traversal

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<TreeNode *> sk;
        auto now = root;
        while (now) {
            res.push_back(now->val);
            if (now->right) {
                sk.push_back(now->right);
            }
            now = now->left;
            if (!now) {
                if (!sk.size()) {
                    break;
                }
                now = sk.back();
                sk.pop_back();
            }
        }
        return res;
    }
};

//--- method 2: preorder recursion
class Solution {
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        if (root) {
            preorder(root);
        }
        return res;
    }
    void preorder(TreeNode *root) {
        res.push_back(root->val);
        if (root->left) {
            preorder(root->left);            
        }
        if (root->right) {
            preorder(root->right);
        }
    }
};

//--- method 3: morris travesal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
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
                    now->right = nullptr;
                    now = prev->right;
                } else {
                    res.push_back(prev->val);
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