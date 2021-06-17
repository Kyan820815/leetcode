//--- Q: 924. Minimize Malware Spread

//--- method 1: union find
class Solution {
public:
    vector<int> sz, parent;
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        vector<int> infec(n, 0);
        sz.resize(n, 0), parent.resize(n, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (graph[i][j]) {
                    int ap = findp(i);
                    int bp = findp(j);
                    if (ap != bp) {
                        if (sz[ap] < sz[bp]) {
                            parent[ap] = bp;
                            sz[bp] += sz[ap];
                        } else {
                            parent[bp] = ap;
                            sz[ap] += sz[bp];
                        }
                    }
                }
            }
        }
        int one = 0;
        for (auto &id: initial) {
            int p = findp(id);
            if (++infec[p] == 1) {
                ++one;
            } else if (infec[p] == 2) {
                --one;
            }
        }
        bool hasone = one > 0;
        int maxv = 0, minid = n;
        for (auto &id: initial) {
            int p = findp(id);
            if (infec[p] == 1) {
                if (maxv < sz[p]) {
                    maxv = sz[p];
                    minid = id;
                } else if (maxv == sz[p] && id < minid) {
                    minid = id;
                }
            } else if (!hasone) {
                minid = min(minid, id);
            }
        }
        return minid;
    }
    int findp(int now) {
        if (parent[now] == now) {
            return now;
        } else {
            if (parent[now] == -1) {
                sz[now] = 1;
                return parent[now] = now;
            } else {
                return parent[now] = findp(parent[now]);
            }
        }
    }
};