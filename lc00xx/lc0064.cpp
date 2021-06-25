//--- Q: 064. Minimum Path Sum

//--- method 1: dfs, space O(mn)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	if (grid.empty()) return 0;
		vector<vector<int>> path(grid.size(), vector<int>(grid[0].size(), 0));
		dfs(grid, path, grid.size()-1, grid[0].size()-1);
		return path[grid.size()-1][grid[0].size()-1];        
    }
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &path, int r, int c)
    {
    	if (!path[r][c])
    	{
    		if (r == 0 && c== 0)
    			path[r][c] = grid[r][c];
    		else if (r == 0)
    			path[r][c] = path[r][c-1]+grid[r][c];
    		else if (c == 0)
    			path[r][c] = path[r-1][c]+grid[r][c];
    		else
    		{
    			dfs(grid, path, r-1, c);
    			dfs(grid, path, r, c-1);
    			path[r][c] = min(path[r][c-1], path[r-1][c])+grid[r][c];
    		}
    	}
    }
};

//--- method 2: iteration, space O(mn)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	if (grid.empty()) return 0;
		int row = grid.size(), col = grid[0].size();
		vector<vector<int>> path(row, vector<int>(col, 0));

		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (i == 0 && j == 0)
					path[0][0] = grid[0][0];
				else if (i == 0)
					path[i][j] = path[i][j-1]+grid[i][j];
				else if (j == 0)
					path[i][j] = path[i-1][j]+grid[i][j];
				else
					path[i][j] = min(path[i][j-1],path[i-1][j])+grid[i][j];
			}
		}
		return path[row-1][col-1];        
    }
};

//--- method 3: iteration, space O(n)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	if (grid.empty()) return 0;
		int row = grid.size(), col = grid[0].size();
		vector<int> path(col, 0);

		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (i == 0 && j == 0)
					path[0] = grid[0][0];
				else if (i == 0)
					path[j] = path[j-1]+grid[i][j];
				else if (j == 0)
					path[j] = path[j]+grid[i][j];
				else
					path[j] = min(path[j-1],path[j])+grid[i][j];
			}
		}
		return path[col-1];        
    }
};