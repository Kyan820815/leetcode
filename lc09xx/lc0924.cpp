//--- Q: 0924. Minimize Malware Spread

//--- method 1: union find
class Solution {
public:
    vector<int> parent, group;
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        vector<int> infectGroup(n, 0);
        parent.resize(n, -1);
        group.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (graph[i][j]) {
                    int ap = findp(i);
                    int bp = findp(j);
                    if (ap != bp) {
                        parent[ap] = bp;
                        group[bp] += group[ap];
                    }
                }
            }
        }
        int hasone = 0;
        for (auto &node: initial) {
            int p = findp(node);
            if (++infectGroup[p] == 1) {
                hasone = 1;
            } else if (infectGroup[p] == 2) {
                hasone = 0;
            }
        }
        int res = 0, residx = n;
        for (auto &node: initial) {
            int p = findp(node);
            if (infectGroup[p] == 1) {
                if (res < group[p]) {
                    res = group[p];
                    residx = node;
                } else if (res == group[p] && node < residx) {
                    residx = node;
                }
            } else if (!hasone && node < residx) {
                residx = node;
            }
        }
        return residx;
    }
    int findp(int now) {
        if (parent[now] == now) {
            return now;
        } else if (parent[now] == -1){
            ++group[now];
            return parent[now] = now;
        } else {
            return parent[now] = findp(parent[now]);
        }
    }
};