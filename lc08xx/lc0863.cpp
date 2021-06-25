//--- Q: 863. All Nodes Distance K in Binary Tree

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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*,vector<TreeNode*>> graph;
        unordered_set<TreeNode *> exist;
        queue<TreeNode *> que;
        int qsize = 1, dis = 0;
        vector<int> res;
        preorder(root, NULL, graph);
        que.push(target);
        exist.insert(target);
        while (que.size())
        {
            for (int i = 0; i < qsize; ++i)
            {
                TreeNode *now = que.front();
                que.pop();
                if (dis == K)
                    res.push_back(now->val);
                for (int j = 0; j < graph[now].size(); ++j)
                {
                    if (exist.count(graph[now][j])) continue;
                    que.push(graph[now][j]);
                    exist.insert(graph[now][j]);
                }
            }
            ++dis;
            if (dis > K) break;
            qsize = que.size();
        }
        return res;
    }
    void preorder(TreeNode *root, TreeNode *parent, unordered_map<TreeNode*,vector<TreeNode*>> &graph)
    {
        if (parent)
        {
            graph[root].push_back(parent);
            graph[parent].push_back(root);
        }
        parent = root;
        if (root->left)
            preorder(root->left, parent, graph);
        if (root->right)
            preorder(root->right, parent, graph);
    }

};