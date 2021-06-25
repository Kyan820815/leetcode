//--- Q: 317. Shortest Distance from All Buildings

//--- method 1: bfs
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), res = INT_MAX, cnt = 0;
        vector<vector<int>> visit(row, vector<int>(col, 0));
        vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    ++cnt;
                    res = INT_MAX;
                    queue<pair<int, int>> que;
                    que.push({i,j});
                    int dis = -1;
                    while (que.size()) {
                        int qsize = que.size();
                        while (qsize--) {
                            auto now = que.front();
                            que.pop();
                            for (int k = 0; k < 4; ++k) {
                                int nr = now.first+dir[k][0];
                                int nc = now.second+dir[k][1];
                                if (nr < 0 || nr >= row || nc < 0 || nc >= col || grid[nr][nc] > 0 || visit[nr][nc]+1 != cnt) {
                                    continue;
                                }
                                grid[nr][nc] += dis;
                                ++visit[nr][nc];
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