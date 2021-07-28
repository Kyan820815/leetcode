//--- Q: 0429. N-ary Tree Level Order Traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

//--- method 1: bfs
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) {
            return {};
        }
        queue<Node *> que;
        que.push(root);
        vector<vector<int>> res;
        while (que.size()) {
            auto qsize = que.size();
            vector<int> tmp;
            while (qsize--) {
                auto now = que.front();
                que.pop();
                tmp.push_back(now->val);
                for (auto &next: now->children) {
                    que.push(next);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};

//--- method 2: preorder dfs
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) {
            return {};
        }
        preorder(root, 0);
        return res;
    }
    void preorder(Node *root, int h) {
        if (h == res.size()) {
            res.push_back({root->val});
        } else {
            res[h].push_back(root->val);
        }
        for (auto &next: root->children) {
            preorder(next, h+1);
        }
    }
};

