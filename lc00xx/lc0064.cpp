//--- Q: 0064. Minimum Path Sum

//--- method 1: dp iteration
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        for (int i = 1; i < row; ++i) {
            grid[i][0] += grid[i-1][0];
        }
        for (int j = 1; j < col; ++j) {
            grid[0][j] += grid[0][j-1];
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[row-1][col-1];
    }
};

//--- method 2: dp recursion, space O(mn)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> visit(row, vector<int>(col, -1));
        return dfs(row-1, col-1, grid, visit);
    }
    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visit) {
        if (i < 0 || j < 0) {
            return INT_MAX;
        }
        if (visit[i][j] != -1) {
            return visit[i][j];
        }
        int minv = min(dfs(i-1, j, grid, visit), dfs(i, j-1, grid, visit));
        return visit[i][j] = grid[i][j] + (minv == INT_MAX ? 0 : minv);
    }
};