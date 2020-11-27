//--- Q: 685. Redundant Connection II

//--- method 1: union find
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0);
        vector<int> first, second;
        for (int i = 0; i < edges.size(); ++i) {
            if (parent[edges[i][1]] == 0) {
                parent[edges[i][1]] = edges[i][0];
            } else {
                first = {parent[edges[i][1]], edges[i][1]};
                second = edges[i];
                edges[i][1] = 0;
            }
        }
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        for (int i = 0; i < edges.size(); ++i) {
            if (edges[i][1] == 0) {
                continue;
            }
            int ap = findP(edges[i][0], parent);
            int bp = findP(edges[i][1], parent);
            if (ap != bp) {
                parent[ap] = bp;
            } else {
                return first.size() ? first : edges[i];
            }
        }
        return second;
    }
    int findP(int now, vector<int> &parent) {
        while (now != parent[now]) {
            now = parent[now];
        }
        return now;
    }
};