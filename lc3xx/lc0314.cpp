//--- Q: 314. Binary Tree Vertical Order Traversal

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, map<int, vector<int>>> m;
        vector<vector<int>> res;
        if (!root)return res;
        preorder(root, 0, 0, m);
        for (auto &c: m) {
            vector<int> tmp;
            for (auto &r: c.second) {
                tmp.insert(tmp.end(), r.second.begin(), r.second.end());
            }
            res.push_back(tmp);
        }
        return res;
    }
    void preorder(TreeNode *root, int r, int c,  map<int, map<int, vector<int>>> &m) {
        m[c][r].push_back(root->val);       
        if (root->left)
            preorder(root->left, r+1, c-1, m);
        if (root->right)
            preorder(root->right, r+1, c+1, m);
    }
};

//--- method 2-1: bfs with map
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> map;
        vector<vector<int>> res;
        queue<pair<int, TreeNode *>> que;
        if (!root)
            return res;
        que.push({0, root});
        while (que.size()) {
            auto now = que.front();
            que.pop();
            map[now.first].push_back(now.second->val);
            if (now.second->left) 
                que.push({now.first-1, now.second->left});
            if (now.second->right)
                que.push({now.first+1, now.second->right});
        }
        for (auto &m: map)
            res.push_back(m.second);
        return res;
    }
};

//--- method 2-2: bfs with unordered_map
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        queue<pair<int, TreeNode *>> que;
        que.push({0, root});
        vector<vector<int>> res;
        unordered_map<int, vector<int>> map;
        int maxcol = INT_MIN, mincol = INT_MAX;
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                mincol = min(mincol, now.first);
                maxcol = max(maxcol, now.first);
                map[now.first].push_back(now.second->val);
                if (now.second->left) {
                    que.push({now.first-1, now.second->left});
                }
                if (now.second->right) {
                    que.push({now.first+1, now.second->right});
                }
            }
        }
        res.resize(maxcol-mincol+1);
        for (auto &m: map) {
            res[m.first-mincol] = m.second;
        }
        return res;
    }

