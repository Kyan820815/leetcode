//--- Q: 0987. Vertical Order Traversal of a Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: bfs with hashmap
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int, map<int, multiset<int>>> map;
        queue<pair<TreeNode *,int>> que;
        int d = 0;
        int minw = INT_MAX, maxw = INT_MIN;
        que.push({root,0});
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                minw = min(minw, now.second);
                maxw = max(maxw, now.second);
                que.pop();
                map[now.second][d].insert(now.first->val);
                if (now.first->left) {
                    que.push({now.first->left, now.second-1});
                }
                if (now.first->right) {
                    que.push({now.first->right, now.second+1});
                }
            }
            ++d;
        }
        int maxd = d-1;
        vector<vector<int>> res;
        for (int i = minw; i <= maxw; ++i) {
            vector<int> tmp;
            for (int j = 0; j <= maxd; ++j) {
                 if (map.find(i) != map.end() && map[i].find(j) != map[i].end()) {
                    tmp.insert(tmp.end(), map[i][j].begin(), map[i][j].end());
                 }
            }
            res.push_back(tmp);
        }
        return res;
    }
};

//--- method 2: dfs (preorder) with hashmap
class Solution {
public:
    map<int, map<int, multiset<int>>> map;
    int maxw = INT_MIN, minw = INT_MAX, maxd = 0;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        preorder(root, 0, 0);
        vector<vector<int>> res;
        for (int i = minw; i <= maxw; ++i) {
            vector<int> tmp;
            for (int j = 0; j <= maxd; ++j) {
                 if (map.find(i) != map.end() && map[i].find(j) != map[i].end()) {
                    tmp.insert(tmp.end(), map[i][j].begin(), map[i][j].end());
                 }
            }
            res.push_back(tmp);
        }
        return res;
    }
    void preorder(TreeNode *root, int x, int y) {
        minw = min(minw, x);
        maxw = max(maxw, x);
        map[x][y].insert(root->val);
        maxd = max(maxd, y);
        if (root->left) {
            preorder(root->left, x-1, y+1);
        }
        if (root->right) {
            preorder(root->right, x+1, y+1);
        }
    }
};