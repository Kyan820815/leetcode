//--- Q: 0515. Find Largest Value in Each Tree Row

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
    vector<int> res;
    vector<int> largestValues(TreeNode* root) {
        if (root) {
            preorder(root, 0);
        }
        return res;
    }
    void preorder(TreeNode *root, int h) {
        if (h == res.size()) {
            res.push_back(root->val);
        } else {
            res[h] = max(res[h], root->val);
        }
        if (root->left) {
            preorder(root->left, h+1);
        }
        if (root->right) {
            preorder(root->right, h+1);
        }
    }
};

//--- method 2: bfs
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        queue<TreeNode *> que;
        que.push(root);
        while (que.size()) {
            auto qsize = que.size();
            auto val = INT_MIN;
            while (qsize--) {
                auto now = que.front();
                que.pop();
                val = max(val, now->val);
                if (now->left) {
                    que.push(now->left);
                }
                if (now->right) {
                    que.push(now->right);
                }
            }
            res.push_back(val);
        }
        return res;
    }
};