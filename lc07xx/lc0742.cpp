//--- Q: 0742. Closest Leaf in a Binary Tree

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
    unordered_map<int, vector<int>> rel;
    unordered_set<int> visit;
    int findClosestLeaf(TreeNode* root, int k) {
        preorder(root, 0);
        queue<int> que;
        que.push(k);
        visit.insert(k);
        visit.insert(0);
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                if (rel[now].size() == 1) {
                    return now;
                }
                for (auto &next: rel[now]) {
                    if (visit.find(next) == visit.end()) {
                        visit.insert(next);
                        que.push(next);
                    }
                }
            }
        }
        return -1;
    }
    void preorder(TreeNode *root, int p) {
        rel[root->val].push_back(p);
        rel[p].push_back(root->val);
        if (root->left) {
            preorder(root->left, root->val);
        }
        if (root->right) {
            preorder(root->right, root->val);
        }
    }
};