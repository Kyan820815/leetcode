//--- Q: 0589. N-ary Tree Preorder Traversal

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

//--- method 1: iterative solution
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        vector<Node *> sk;
        while (root) {
            res.push_back(root->val);
            if (root->children.size()) {
                for (int i = root->children.size()-1; i > 0; --i) {
                    sk.push_back(root->children[i]);
                }
                root = root->children[0];
            } else {
                root = nullptr;
            }
            if (!root && sk.size()) {
                root = sk.back();
                sk.pop_back();
            }
        }
        return res;
    }
};

//--- method 2: recursion
class Solution {
public:
    vector<int> res;
    vector<int> preorder(Node* root) {
        if (root) {
            dfs(root);
        }
        return res;
    }
    void dfs(Node *root) {
        res.push_back(root->val);
        for (auto &child: root->children) {
            dfs(child);
        }
    }
};