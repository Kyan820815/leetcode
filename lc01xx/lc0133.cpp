//--- Q: 0133. Clone Graph

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

//--- method 1: dfs
class Solution {
public:
    unordered_map<Node *, Node *> map;
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        return dfs(node);
    }
    Node *dfs(Node *now) {
        if (map.find(now) != map.end()) {
            return map[now];
        }
        map[now] = new Node(now->val);
        for (auto &neib: now->neighbors) {
            map[now]->neighbors.push_back(dfs(neib));
        }
        return map[now];
    }
};