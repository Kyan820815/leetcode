//--- Q: 1368. Minimum Cost to Make at Least One Valid Path in a Grid

//--- method 1: bfs two queue
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> visit(row, vector<int>(col, INT_MAX));
        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        queue<pair<int,int>> que1, que2;
        que1.push({0,0});
        visit[0][0] = 0;
        while (que1.size() || que2.size()) {
            while (que1.size()) {
                auto qsize = que1.size();
                while (qsize--) {
                    auto now = que1.front();
                    que1.pop();
                    int r = now.first, c = now.second;
                    if (r == row-1 && c == col-1) {
                        return visit[r][c];
                    }
                    for (int i = 0; i < dirs.size(); ++i) {
                        int nr = r+dirs[i][0];
                        int nc = c+dirs[i][1];
                        if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
                            continue;
                        }
                        if (i+1 == grid[r][c]) {
                            if (visit[nr][nc] > visit[r][c]) {
                                visit[nr][nc] = visit[r][c];
                                que1.push({nr,nc});
                            }
                        } else if (visit[nr][nc] > visit[r][c]+1) {
                            visit[nr][nc] = visit[r][c]+1;
                            que2.push({nr,nc});
                        }
                    }
                }
            }
            if (!que1.size()) {
                que1 = que2;
                queue<pair<int,int>> empty;
                swap(que2, empty);
            }
            if (visit[row-1][col-1] != INT_MAX) {
                break;
            }
        }
        return visit[row-1][col-1];
    }
};

//--- method 2: dijkstra
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> visit(row, vector<int>(col, INT_MAX));
        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        auto comp = [](const array<int,3> &a, const array<int,3> &b) {
            return a[2] > b[2];
        };
        priority_queue<array<int,3>, vector<array<int,3>>, decltype(comp)> que(comp);
        que.push({0,0,0});
        visit[0][0] = 0;
        while (que.size()) {
            auto now = que.top();
            que.pop();
            int r = now[0], c = now[1], cost = now[2];
            if (r == row-1 && c == col-1) {
                return cost;
            }
            for (int i = 0; i < dirs.size(); ++i) {
                int nr = r+dirs[i][0];
                int nc = c+dirs[i][1];
                if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
                    continue;
                }
                if (i+1 == grid[r][c]) {
                    if (visit[nr][nc] > cost) {
                        visit[nr][nc] = cost;
                        que.push({nr,nc,cost});
                    }
                } else if (visit[nr][nc] > cost+1) {
                    visit[nr][nc] = cost+1;
                    que.push({nr,nc,cost+1});
                }
            }
        }
        return visit[row-1][col-1];
    }
};