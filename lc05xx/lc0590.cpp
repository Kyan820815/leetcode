//--- Q: 0590. N-ary Tree Postorder Traversal

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

//--- method 1: iterative stack
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        vector<Node *> sk;
        sk.push_back(root);
        Node *last = root;
        while (sk.size()) {
            auto now = sk.back();
            if (!now->children.size()) {
                last = now;
                sk.pop_back();
                res.push_back(now->val);
            } else {
                int find = 0;
                for (auto &child: now->children) {
                    if (child == last) {
                        find = 1;
                        last = now;
                        sk.pop_back();
                        res.push_back(now->val);
                        break;
                    }
                }
                if (!find) {
                    for (int i = now->children.size()-1; i >= 0; --i) {
                        sk.push_back(now->children[i]);
                    }
                }
            }
        }
        return res;
    }
};

//--- method 2: recursion
class Solution {
public:
    vector<int> res;
    vector<int> postorder(Node* root) {
        if (root) {
            dfs(root);
        }
        return res;
    }
    void dfs(Node *root) {
        for (auto &child: root->children) {
            dfs(child);
        }
        res.push_back(root->val);
    }
};