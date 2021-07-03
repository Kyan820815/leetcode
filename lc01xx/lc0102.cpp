//--- Q: 0102. Binary Tree Level Order Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- mehtod 1: dfs (preorder), better cuz more clean
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root) {
            preorder(0, root);
        }
        return res;
    }
    void preorder(int h, TreeNode *root) {
        if (h == res.size()) {
            res.push_back({root->val});
        } else {
            res[h].push_back(root->val);
        }
        if (root->left) {
            preorder(h+1, root->left);
        }
        if (root->right) {
            preorder(h+1, root->right);
        }
    }
};

//--- method 2: bfs
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode *> que;
        que.push(root);
        while (que.size()) {
            auto qsize = que.size();
            vector<int> tmp;
            while (qsize--) {
                auto now = que.front();
                que.pop();
                tmp.push_back(now->val);
                if (now->left) {
                    que.push(now->left);
                }
                if (now->right) {
                    que.push(now->right);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};