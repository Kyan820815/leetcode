//--- Q: 0547. Friend Circles

//--- method 1: union find
class Solution {
public:
    vector<int> parent;
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), res = n;
        parent.resize(n, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (isConnected[i][j]) {
                    int ap = findp(i);
                    int bp = findp(j);
                    if (ap != bp) {
                        parent[ap] = bp;
                        --res;
                    }
                }
            }
        }
        return res;
    }
    int findp(int now) {
        if (parent[now] == now) {
            return now;
        } else {
            return parent[now] = parent[now] == -1 ? now : findp(parent[now]);
        }
    }
};

//--- method 2: dfs
class Solution {
public:
    vector<int> visit;
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), res = 0;
        visit.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            if (!visit[i]) {
                dfs(i, isConnected);
                ++res;
            }
        }
        return res;
    }
    void dfs(int now, vector<vector<int>> &isConnected) {
        visit[now] = 1;
        for (int i = 0; i < isConnected[now].size(); ++i) {
            if (isConnected[now][i] && !visit[i]) {
                dfs(i, isConnected);
            }
        }
    }
};