//--- Q: 1020. Number of Enclaves

//--- method 1: dfs recursion
class Solution {
public:
    int row, col, res;
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int numEnclaves(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size(), res = 0;
        for (int i = 0; i < row; ++i) {
            if (grid[i][0]) {
                dfs(i, 0, grid);
            }
            if (grid[i][col-1]) {
                dfs(i, col-1, grid);
            }
        }
        for (int j = 0; j < col; ++j) {
            if (grid[0][j]) {
                dfs(0, j, grid);
            }
            if (grid[row-1][j]) {
                dfs(row-1, j, grid);
            }
        }
        res = 0;
        for (int i = 1; i < row-1; ++i) {
            for (int j = 1; j < col-1; ++j) {
                res += grid[i][j];
            }
        }
        return res;
    }
    void dfs(int r, int c, vector<vector<int>> &grid) {
        grid[r][c] = 0;
        for (auto &dir: dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || !grid[nr][nc]) {
                continue;
            }
            dfs(nr, nc, grid);
        }
    }
};