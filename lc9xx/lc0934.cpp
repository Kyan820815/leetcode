//--- Q: 934. Shortest Bridge

//--- method 1: dfs+bfs
class Solution {
public:
    int row, col;
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    queue<pair<int,int>> que;
    int shortestBridge(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();
        int find = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j]) {
                    dfs(i, j, grid);
                    find = 1;
                    break;
                }
            }
            if (find) {
                break;
            }
        }
        int res = 0;
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                for (auto &dir: dirs) {
                    int nr = now.first+dir[0];
                    int nc = now.second+dir[1];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col || grid[nr][nc] == -1) {
                        continue;
                    }
                    if (grid[nr][nc] == 1) {
                        return res;
                    }
                    grid[nr][nc] = -1;
                    que.push({nr,nc});
                }
            }
            ++res;
        }
        return -1;
    }
    void dfs(int r, int c, vector<vector<int>> &grid) {
        bool edge = false;
        grid[r][c] = -1;
        for (auto &dir: dirs) {
            int nr = r+dir[0];
            int nc = c+dir[1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || !grid[nr][nc]) {
                edge = true;
                continue;
            }
            if (grid[nr][nc] == 1) {
                dfs(nr, nc, grid);
            }
        }
        if (edge) {
            que.push({r,c});
        }
    }
};