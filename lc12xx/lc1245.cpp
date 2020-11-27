//--- Q: 1245. Tree Diameter

//--- method 1: bfs
class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<vector<int>> rel(n);
        vector<int> deg(n, 0);
        for (int i = 0; i < edges.size(); ++i) {
            rel[edges[i][0]].push_back(edges[i][1]);
            rel[edges[i][1]].push_back(edges[i][0]);
            ++deg[edges[i][0]];
            ++deg[edges[i][1]];
        }
        queue<int> que;
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 1) {
                que.push(i);
            }
        }
        int res = 0;
        while (que.size() > 1) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                for (int j = 0; j < rel[now].size(); ++j) {
                    if (--deg[rel[now][j]] == 1) {
                        que.push(rel[now][j]);
                    }
                }
            }
            ++res;
        }
        return que.size() == 1 ? 2*res : 2*res - 1;
    }
};

//--- method 2: dfs
class Solution {
public:
    int res = 0;
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<vector<int>> rel(n);
        for (int i = 0; i < edges.size(); ++i) {
            rel[edges[i][0]].push_back(edges[i][1]);
            rel[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(-1, 0, rel);
        return res;
    }
    int dfs(int p, int now, vector<vector<int>> &rel) {
        int first = 0, second = 0;
        for (int i = 0; i < rel[now].size(); ++i) {
            if (rel[now][i] == p) {
                continue;
            }
            int val = dfs(now, rel[now][i], rel);
            if (first < val) {
                second = first;
                first = val;
            } else if (second < val) {
                second = val;
            }
        }
        res = max(res, first + second);
        return max(first, second) + 1;
    }
};
