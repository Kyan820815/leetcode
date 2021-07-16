//--- Q: 0317. Shortest Distance from All Buildings

//--- method 1: bfs
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int row = grid.size(), col = grid[0].size(), res = INT_MAX, buildings = 0;
        vector<vector<int>> cnt(row, vector<int>(col, 0));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    res = INT_MAX;
                    queue<pair<int,int>> que;
                    que.push({i,j});
                    ++buildings;
                    int dis = -1;
                    while (que.size()) {
                        auto qsize = que.size();
                        while (qsize--) {
                            auto now = que.front();
                            que.pop();
                            for (auto &dir: dirs) {
                                int nr = now.first + dir[0];
                                int nc = now.second + dir[1];
                                if (nr < 0 || nr >= row || nc < 0 || nc >= col || grid[nr][nc] > 0) {
                                    continue;
                                }
                                if (cnt[nr][nc]+1 != buildings) {
                                    continue;
                                }
                                ++cnt[nr][nc];
                                grid[nr][nc] += dis;
                                res = min(res, abs(grid[nr][nc]));
                                que.push({nr, nc});
                            }
                        }
                        --dis;
                    }
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};