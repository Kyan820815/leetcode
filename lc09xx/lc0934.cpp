//--- Q: 0934. Shortest Bridge

//--- method 1: dfs+bfs
class Solution {
public:
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int row, col;
    queue<pair<int,int>> que;
    int shortestBridge(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();
        int find = 0;
        for (int i = 0; i < row && !find; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j]) {
                    dfs(i, j, grid);
                    find = 1;
                    break;
                }
            }
        }
        int res = 0;
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                int r = now.first, c = now.second;
                for (auto &dir: dirs) {
                    int nr = r+dir[0];
                    int nc = c+dir[1];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
                        continue;
                    }
                    if (grid[nr][nc] == 0) {
                        grid[nr][nc] = -1;
                        que.push({nr,nc});
                    } else if (grid[nr][nc] == 1) {
                        return res;
                    }
                }
            }
            ++res;
        }
        return -1;
    }
    void dfs(int r, int c, vector<vector<int>> &grid) {
        bool isedge = false;
        grid[r][c] = -1;
        for (auto &dir: dirs) {
            int nr = r+dir[0];
            int nc = c+dir[1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || !grid[nr][nc]) {
                isedge = true;
                continue;
            }
            if (grid[nr][nc] == 1) {
                dfs(nr,nc,grid);
            }
        }
        if (isedge) {
            que.push({r,c});
        }
    }
};