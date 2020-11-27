//--- Q: 133. Clone Graph

//--- method 1: dfs
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
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node *, Node *> map;
        return dfs(node, map);
    }
    Node *dfs(Node *node, unordered_map<Node *, Node *> &map)
    {
        if (map.find(node) != map.end()) return map[node];
        map[node] = new Node(node->val);
        for (int i = 0; i < node->neighbors.size(); ++i)
        {
            map[node]->neighbors.push_back(dfs(node->neighbors[i], map));
        }
        return map[node];
    }
};