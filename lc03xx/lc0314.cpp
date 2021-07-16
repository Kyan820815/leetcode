//--- Q: 0314. Binary Tree Vertical Order Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: bfs with map
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        queue<pair<TreeNode *, int>> que;
        que.push({root, 0});
        map<int, vector<int>> map;
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                map[now.second].push_back(now.first->val);
                if (now.first->left) {
                    que.push({now.first->left, now.second-1});
                }
                if (now.first->right) {
                    que.push({now.first->right, now.second+1});
                }
            }
        }
        for (auto &vec: map) {
            res.push_back(vec.second);
        }
        return res;
    }
};

//--- method 2: bfs with unordered_map
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        queue<pair<TreeNode *, int>> que;
        que.push({root, 0});
        unordered_map<int, vector<int>> map;
        int minx = 0, maxx = 0;
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                minx = min(minx, now.second);
                maxx = max(maxx, now.second);
                que.pop();
                map[now.second].push_back(now.first->val);
                if (now.first->left) {
                    que.push({now.first->left, now.second-1});
                }
                if (now.first->right) {
                    que.push({now.first->right, now.second+1});
                }
            }
        }
        for (int i = minx; i <= maxx; ++i) {
            res.push_back(map[i]);
        }
        return res;
    }
};
