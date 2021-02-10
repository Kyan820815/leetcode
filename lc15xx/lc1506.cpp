//--- Q: 1506. Find Root of N-Ary Tree

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

//--- method 1: O(n) space
class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        unordered_map<Node *, int> deg;
        for (auto &node: tree) {
            for (auto &child: node->children) {
                ++deg[child];
            }
        }
        for (auto &node: tree) {
            if (!deg[node]) {
                return node;
            }
        }
        return NULL;
    }
};

//--- method 2: O(1) space
class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        int val = 0;
        for (auto &node: tree) {
            val ^= node->val;
            for (auto &child: node->children) {
                val ^= child->val;
            }
        }
        for (auto &node: tree) {
            if (node->val == val) {
                return node;
            }
        }
        return NULL;
    }
};