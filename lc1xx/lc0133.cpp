//--- Q: 133. Clone Graph

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
            return NULL;
        }
        if (map.find(node) != map.end()) {
            return map[node];
        }
        map[node] = new Node(node->val);
        for (auto &neigh: node->neighbors) {
            map[node]->neighbors.push_back(cloneGraph(neigh));
        }
        return map[node];
    }
};