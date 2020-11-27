//--- Q: 742. Closest Leaf in a Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//--- method 1: dfs+bfs
class Solution {
public:
    int findClosestLeaf(TreeNode* root, int k) {
        rel.resize(1001);
        visit.resize(1001);
        dfs(root, 0);
        queue<int> que;
        que.push(k);
        visit[k] = visit[0] = 1;
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                if (rel[now].size() == 1) {
                    return now;
                }
                for (int j = 0; j < rel[now].size(); ++j) {
                    if (visit[rel[now][j]]) {
                        continue;
                    }
                    visit[rel[now][j]] = 1;
                    que.push(rel[now][j]);
                }
            }
        }
        return -1;
    }
    void dfs(TreeNode *root, int parent) {
        rel[parent].push_back(root->val);
        rel[root->val].push_back(parent);
        if (root->left) {
            dfs(root->left, root->val);
        }
        if (root->right) {
            dfs(root->right, root->val);
        }
    }
    vector<vector<int>> rel;
    vector<int> visit;
};