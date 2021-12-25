//--- Q: 0863. All Nodes Distance K in Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs+bfs
class Solution {
public:
    unordered_map<int, vector<int>> rel;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, -1);
        unordered_set<int> visit;
        visit.insert(-1);
        visit.insert(target->val);
        vector<int> res;
        queue<int> que;
        que.push(target->val);
        while (que.size() && k >= 0) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                if (!k) {
                    res.push_back(now);
                } else {
                    for (auto &next: rel[now]) {
                        if (visit.find(next) == visit.end()) {
                            visit.insert(next);
                            que.push(next);
                        }
                    }
                }
            }
            --k;
        }
        return res;
    }
    void dfs(TreeNode *root, int p) {
        rel[root->val].push_back(p);
        rel[p].push_back(root->val);
        if (root->left) {
            dfs(root->left, root->val);
        }
        if (root->right) {
            dfs(root->right, root->val);
        }
    }
};