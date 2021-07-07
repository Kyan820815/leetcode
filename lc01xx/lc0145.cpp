//--- Q: 0145. Binary Tree Postorder Traversal

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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        TreeNode *last = root;
        vector<TreeNode *> sk;
        vector<int> res;
        sk.push_back(root);
        while (sk.size()) {
            auto now = sk.back();
            if (!now->left && !now->right || now->left == last || now->right == last) {
                last = now;
                res.push_back(now->val);
                sk.pop_back();
            } else {
                if (now->right) {
                    sk.push_back(now->right);
                }
                if (now->left) {
                    sk.push_back(now->left);
                }
            }
        }
        return res;
    }
};
//--- method 2: postorder recursion
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> out;
        if (!root) return out;
        postorder(root, out);
        return out;   
    }
    void postorder(TreeNode *root, vector<int> &out)
    {   
        if (root->left) postorder(root->left, out);
        if (root->right) postorder(root->right, out);
        out.push_back(root->val);
    }
};

//--- method 3: morris travesal
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        auto dummy = new TreeNode(-1, root, nullptr), now = dummy;
        vector<int> res;
        while (now) {
            if (now->left) {
                auto prev = now;
                now = prev->left;
                while (now->right && now->right != prev) {
                    now = now->right;
                }
                if (now->right) {
                    auto cur = prev->left;
                    int start_sz = res.size();
                    while (cur != prev) {
                        res.push_back(cur->val);
                        cur = cur->right;
                    }
                    reverse(res.begin()+start_sz, res.end());
                    now->right = NULL;
                    now = prev->right;
                } else {
                    now->right = prev;
                    now = prev->left;
                }
            } else {
                now = now->right;
            } 
        }
        return res;
    }
};