//--- Q: 1254. Number of Closed Islands

//--- method 1: one dfs
class Solution {
public:
    vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), cnt = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (!grid[i][j]) {
                    grid[i][j] = 1;
                    if (!dfs(i, j, grid)) {
                        ++cnt;
                    }
                }
            }
        }
        return cnt;
    }
    int dfs(int r, int c, vector<vector<int>> &grid) {
        int row = grid.size(), col = grid[0].size();
        bool boarder = false;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
                boarder = true;
                continue;
            }
            if (!grid[nr][nc]) {
                grid[nr][nc] = 1;
                boarder |= dfs(nr, nc, grid);
            }
        }
        return boarder;
    }
};

//--- method 2: double dfs
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int cnt = 0;
        row = grid.size(), col = grid[0].size();
        dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for (int i = 0; i < row; ++i) {
            if (!grid[i][0]) {
                dfs(i, 0, grid);
            }
            if (!grid[i][col-1]) {
                dfs(i, col-1, grid);
            }
        }
        for (int j = 0; j < col; ++j) {
            if (!grid[0][j]) {
                dfs(0, j, grid);
            }
            if (!grid[row-1][j]) {
                dfs(row-1, j, grid);
            }
        }
        for (int i = 1; i < row-1; ++i) {
            for (int j = 1; j < col-1; ++j) {
                if (!grid[i][j]) {
                    ++cnt;
                    dfs(i, j, grid);
                }
            }
        }
        return cnt;
    }
    void dfs(int r, int c, vector<vector<int>> &grid) {
        grid[r][c] = 1;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || grid[nr][nc]) {
                continue;
            }
            dfs(nr, nc, grid);
        }
    }
    vector<vector<int>> dir;
    int row, col;
};