//--- Q: 1129. Shortest Path with Alternating Colors

//--- method 1: bfs
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<vector<int>>> rel(2, vector<vector<int>>(n));
        vector<int> res(n);
        queue<pair<int, int>> que;
        for (int i = 0; i < red_edges.size(); ++i)
            rel[0][red_edges[i][0]].push_back(red_edges[i][1]);
        for (int i = 0; i < blue_edges.size(); ++i)
            rel[1][blue_edges[i][0]].push_back(blue_edges[i][1]);
        que.push({0, 0});
        que.push({1, 0});
        
        vector<vector<int>> path(2, vector<int>(n, 2*n));
        path[0][0] = path[1][0] = 0;
        int qsize = que.size();
        while (qsize) {
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                int color = now.first, node = now.second;
                for (int j = 0; j < rel[color^1][node].size(); ++j) {
                    int next_node = rel[color^1][node][j];
                    if (path[color^1][next_node] == 2*n) {
                        path[color^1][next_node] = path[color][node] + 1;
                        que.push({color^1, rel[color^1][node][j]});
                    }
                }
            }
            qsize = que.size();
        }
        for (int i = 1; i < n; ++i) {
            res[i] = min(path[0][i], path[1][i]);
            if (res[i] == 2*n)
                res[i] = -1;
        }
        return res;
    }
};

//--- method 1-2: bfs with red blue variable
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int> res(n), red(n, INT_MAX), blue(n, INT_MAX);
        vector<vector<int>> red_rel(n), blue_rel(n);
        for (int i = 0; i < red_edges.size(); ++i) {
            red_rel[red_edges[i][0]].push_back(red_edges[i][1]);
        }
        for (int i = 0; i < blue_edges.size(); ++i) {
            blue_rel[blue_edges[i][0]].push_back(blue_edges[i][1]);
        }
        red[0] = blue[0] = 0;
        queue<pair<int, int>> que;
        que.push({0, 0});
        que.push({0, 1});
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                if (!now.second) {
                    for (int j = 0; j < red_rel[now.first].size(); ++j) {
                        if (blue[red_rel[now.first][j]] > red[now.first]+1) {
                            blue[red_rel[now.first][j]] = red[now.first]+1;
                            que.push({red_rel[now.first][j], 1});
                        }
                    }
                } else {
                    for (int j = 0; j < blue_rel[now.first].size(); ++j) {
                        if (red[blue_rel[now.first][j]] > blue[now.first]+1) {
                            red[blue_rel[now.first][j]] = blue[now.first]+1;
                            que.push({blue_rel[now.first][j], 0});
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            res[i] = min(blue[i], red[i]);
            if (res[i] == INT_MAX) {
                res[i] = -1;
            }
        }
        return res;
    }
};