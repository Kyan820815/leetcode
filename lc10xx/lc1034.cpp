//--- Q: 1034. Coloring A Border

//--- method 1: dfs
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int tagcolor = grid[r0][c0];
        int row = grid.size(), col = grid[0].size();
        dfs(grid, r0, c0, tagcolor);
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] < 0)
                    grid[i][j] = color;
            }
        }
        return grid;
    }
    void dfs(vector<vector<int>> &grid, int r, int c, int tagcolor)
    {
        int row = grid.size(), col = grid[0].size();
        grid[r][c] = -tagcolor;
        
        if (r-1 >= 0 && grid[r-1][c] == tagcolor)
            dfs(grid, r-1, c, tagcolor);
        if (c-1 >= 0 && grid[r][c-1] == tagcolor)
            dfs(grid, r, c-1, tagcolor);
        if (r+1 < row && grid[r+1][c] == tagcolor)
            dfs(grid, r+1, c, tagcolor);
        if (c+1 < col && grid[r][c+1] == tagcolor)
            dfs(grid, r, c+1, tagcolor);
        if (r > 0 && r < row-1 && c > 0 && c < col-1 &&
           abs(grid[r-1][c]) == tagcolor && abs(grid[r+1][c]) == tagcolor && 
            abs(grid[r][c-1]) == tagcolor && abs(grid[r][c+1]) == tagcolor)
            grid[r][c] = tagcolor;
    }
};