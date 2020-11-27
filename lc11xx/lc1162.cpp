//--- Q: 1162. As Far from Land as Possible

//--- method 1: bfs
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), res = 0;
        vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        queue<pair<int, int>> que;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    que.push({i, j});
                }
            }
        }
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                for (int j = 0; j < 4; ++j) {
                    int nr = now.first + dir[j][0];
                    int nc = now.second + dir[j][1];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col || grid[nr][nc] != 0) {
                        continue;
                    }
                    grid[nr][nc] = grid[now.first][now.second] + abs(nr-now.first) + abs(nc-now.second);
                    res = max(res, grid[nr][nc]);
                    que.push({nr, nc});
                }
            }
        }
        return res - 1;
    }
};