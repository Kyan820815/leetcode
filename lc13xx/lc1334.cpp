//--- Q: 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

//--- method 1: dfs
class Solution {
public:
    vector<vector<array<int,2>>> rel;
    vector<int> size;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        rel.resize(n);
        size.resize(n, 0);
        for (auto &edge: edges) {
            rel[edge[0]].push_back({edge[1], edge[2]});
            rel[edge[1]].push_back({edge[0], edge[2]});
        }
        
        for (int i = 0; i < n; ++i) {
            vector<int> visit(n, INT_MAX);
            dfs(i, i, 0, distanceThreshold, visit);
        }
        int res = n, residx;
        for (int i = 0; i < n; ++i) {
            if (res >= size[i]) {
                res = size[i];
                residx = i;
            }
        }
        return residx;
    }
    void dfs(int start, int now, int d, int t, vector<int> &visit) {
        if (visit[now] == INT_MAX) {
            ++size[start];
        }
        visit[now] = d;
        for (auto &next: rel[now]) {
            if (d + next[1] <= t && visit[next[0]] > d+next[1]) {
                dfs(start, next[0], d+next[1], t, visit);
            }
        }
    }
};

//--- method 2: Floyd Warshall
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> rel(n, vector<int>(n, 10001));
        for (auto &edge: edges) {
            rel[edge[0]][edge[1]] = rel[edge[1]][edge[0]] = edge[2];
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    int newdis = rel[i][k] + rel[k][j];
                    if (newdis < rel[i][j]) {
                        rel[i][j] = newdis;
                    }
                }
            }
        }
        int res = n, residx;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && rel[i][j] <= distanceThreshold) {
                    ++cnt;
                }
            }
            if (res >= cnt) {
                res = cnt;
                residx = i;
            }
        }
        return residx;
    }
};

