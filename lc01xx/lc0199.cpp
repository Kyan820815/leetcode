//--- Q: 0199. Binary Tree Right Side View

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //--- method 1: bfs
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> res;
        queue<TreeNode *> que;
        que.push(root);
        while (que.size()) {
            auto qsize = que.size();
            res.push_back(que.front()->val);
            while (qsize--) {
                auto now = que.front();
                que.pop();
                if (now->right) {
                    que.push(now->right);
                }
                if (now->left) {
                    que.push(now->left);
                }
            }
        }
        return res;
    }
};

//--- method 2: dfs
class Solution {
public:
    vector<int> res;
    vector<int> rightSideView(TreeNode* root) {
        if (root) {
            dfs(0, root);
        }
        return res;
    }
    void dfs(int h, TreeNode *root) {
        if (h == res.size()) {
            res.push_back(root->val);
        }
        if (root->right) {
            dfs(h+1, root->right);
        }
        if (root->left) {
            dfs(h+1, root->left);
        }
    }
};