//--- Q: 0323. Number of Connected Components in an Undirected Graph

//--- method 1: union find
class Solution {
public:
    vector<int> parent;
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n, -1);
        for (auto &edge: edges) {
            int ap = findp(edge[0]);
            int bp = findp(edge[1]);
            if (ap != bp) {
                parent[ap] = bp;
                --n;
            }
        }
        return n;
    }
    int findp(int now) {
        if (parent[now] == now) {
            return parent[now];
        } else {
            return parent[now] = parent[now] == -1 ? now : findp(parent[now]);
        }
    }
};

//--- method 2: dfs
 class Solution {
public:
    vector<int> visit;
    vector<vector<int>> rel;
    int countComponents(int n, vector<vector<int>>& edges) {
        visit.resize(n, 0);
        rel.resize(n);
        for (auto &edge: edges) {
            rel[edge[0]].push_back(edge[1]);
            rel[edge[1]].push_back(edge[0]);
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (!visit[i]) {
                dfs(i);
                ++res;
            }
        }
        return res;
    }
    void dfs(int now) {
        if (visit[now]) {
            return;
        }
        visit[now] = 1;
        for (auto &next: rel[now]) {
            dfs(next);
        }
    }
};