//--- Q: 980. Unique Paths III

//--- method 1: dfs
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
    	int row = grid.size(), col = grid[0].size();
        int res = 0, quan = 2, r, c;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == 0)
                    ++quan;
                else if (grid[i][j] == 1)
                {
                    r = i;
                    c = j;
                }
            }
        }
        dfs(grid, r, c, quan, res);
        return res;
    }
    void dfs(vector<vector<int>> &grid, int r, int c, int number, int &res)
    {
    	if (grid[r][c] == -1) return;
    	number--;
    	if (grid[r][c] == 2 && !number)
    	{
    		++res;
    		return;
    	}
    	int row = grid.size(), col = grid[0].size();
    	int now = grid[r][c];
    	grid[r][c] = -1;
        if (r-1 >= 0)
    		dfs(grid, r-1, c, number, res);
        if (r+1 < row)
    		dfs(grid, r+1, c, number, res);
        if (c-1 >= 0)
    		dfs(grid, r, c-1, number, res);
        if (c+1 < col)
    		dfs(grid, r, c+1, number, res);
    	grid[r][c] = now;
    }
};