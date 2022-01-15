//--- Q: 1034. Coloring A Border

//--- method 1: dfs
class Solution {
public:
    int rows, cols;
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        rows = grid.size(), cols = grid[0].size();
        if (grid[row][col] == color) {
            return grid;
        }
        dfs(row, col, grid, grid[row][col]);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] < 0) {
                    grid[i][j] = color;
                }
            }
        }
        return grid;
    }
    void dfs(int r, int c, vector<vector<int>> &grid, int ori) {
        bool board = false;
        grid[r][c] *= -1;
        for (auto &dir: dirs) {
            int nr = r+dir[0];
            int nc = c+dir[1];
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || abs(grid[nr][nc]) != ori) {
                board = true;
                continue;
            }
            if (grid[nr][nc] > 0) {
                dfs(nr, nc, grid, ori);
            }
        }
        if (!board) {
            grid[r][c] *= -1;
        }
    }
};