//--- Q: 463. Island Perimeter

//--- method 1: dfs
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (!grid.size()) return 0;
        int res = 0;
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == 1)
                {
                    dfs(grid, i, j, res);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>> &grid, int r, int c, int &res)
    {
        int cnt = 4;
        int row = grid.size(), col = grid[0].size();
        grid[r][c] = 2;
        if (r-1 >= 0 && (grid[r-1][c] == 1 || grid[r-1][c] == 2))
        {
            cnt--;
            if (grid[r-1][c] == 1)
                dfs(grid, r-1, c, res);
        }
        if (r+1 < row && (grid[r+1][c] == 1 || grid[r+1][c] == 2))
        {
            cnt--;
            if (grid[r+1][c] == 1)
                dfs(grid, r+1, c, res);
        }
        if (c-1 >= 0 && (grid[r][c-1] == 1 || grid[r][c-1] == 2))
        {
            cnt--;
            if (grid[r][c-1] == 1)
                dfs(grid, r, c-1, res);
        }
        if (c+1 < col && (grid[r][c+1] == 1 || grid[r][c+1] == 2))
        {
            cnt--;
            if (grid[r][c+1] == 1)
                dfs(grid, r, c+1, res);
        }
        res += cnt;
    }
};

//--- method 2: compute perimeter with subtracting duplicate side length
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (!grid.size()) return 0;
        int res = 0, repeat = 0;
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == 1)
                {
                    res++;
                    if (i-1 >= 0 && grid[i-1][j] == 1) ++repeat;
                    if (j-1 >= 0 && grid[i][j-1] == 1) ++repeat;
                }
            }
        }
        return res*4-2*repeat;
    }
};