//--- Q: 0685. Redundant Connection II

//--- method 1: union find
class Solution {
public:
    vector<int> parent;
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1, -1);
        vector<int> first, second;
        for (auto &edge: edges) {
            if (parent[edge[1]] != -1) {
                second = edge;
                first = {parent[edge[1]], edge[1]};
                edge[0] = -1;
                break;
            }
            parent[edge[1]] = edge[0];
        }
        parent.clear();
        parent.resize(n+1, -1);
        for (auto &edge: edges) {
            if (edge[0] == -1) {
                continue;
            }
            int ap = findp(edge[0]);
            int bp = findp(edge[1]);
            if (ap != bp) {
                parent[ap] = bp;
            } else {
                return first.size() ? first : edge;
            }
        }
        return second;
    }
    int findp(int now) {
        if (parent[now] == now) {
            return now;
        } else {
            return parent[now] = parent[now] == -1 ? now : findp(parent[now]);
        }
    }
};