//--- Q: 1971. Find if Path Exists in Graph

//--- method 1: dfs recursion
class Solution {
public:
    vector<vector<int>> rel;
    vector<int> visit;
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        rel.resize(n);
        visit.resize(n, -1);
        for (auto &edge: edges) {
            rel[edge[0]].push_back(edge[1]);
            rel[edge[1]].push_back(edge[0]);
        }
        return dfs(start, end);
    }
    int dfs(int now, int end) {
        if (visit[now] != -1) {
            return visit[now];
        }
        if (now == end) {
            return visit[now] = 1;
        }
        visit[now] = 0;
        for (auto &next: rel[now]) {
            if (dfs(next, end) == 1) {
                return visit[now] = 1;
            }
        }
        return visit[now];
    }
};

//--- method 2: unifion find
class Solution {
public:
    vector<int> parent;
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        parent.resize(n, -1);
        for (auto &edge: edges) {
            int ap = findp(edge[0]);
            int bp = findp(edge[1]);
            if (ap != bp) {
                parent[ap] = bp;
            }
        }
        return findp(start) == findp(end);
    }
    int findp(int now) {
        if (parent[now] == now) {
            return now;
        } else {
            return parent[now] = parent[now] == -1 ? now : findp(parent[now]);
        }
    }
};

