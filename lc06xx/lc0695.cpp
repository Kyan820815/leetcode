//--- Q: 695. Max Area of Island

//--- method 1: dfs
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int maxArea = 0;
        for (int i = 0; i < row; ++i)
        {
        	for (int j = 0; j < col; ++j)
        	{
        		if (grid[i][j])
        			maxArea = max(maxArea, dfs(grid, i, j, row, col));
        	}
        }
        return maxArea;
    }
    int dfs(vector<vector<int>> &grid, int r, int c, int row, int col)
    {
    	int area = 1;
    	grid[r][c] = 0;
    	if (r-1 >= 0 && grid[r-1][c])
    		area += dfs(grid, r-1, c, row, col);
    	if (c-1 >= 0 && grid[r][c-1])
    		area += dfs(grid, r, c-1, row, col);
    	if (r+1 < row && grid[r+1][c])
    		area += dfs(grid, r+1, c, row, col);
    	if (c+1 < col && grid[r][c+1])
    		area += dfs(grid, r, c+1, row, col);
    	return area;
    }
};

//--- method 2: bfs
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int maxArea = 0;
        for (int i = 0; i < row; ++i)
        {
        	for (int j = 0; j < col; ++j)
        	{
        		if (grid[i][j])
        			maxArea = max(maxArea, dfs(grid, i, j, row, col));
        	}
        }
        return maxArea;
    }
    int dfs(vector<vector<int>> &grid, int r, int c, int row, int col)
    {
    	int area = 1;
    	queue<pair<int,int>> que;
    	que.push({r,c});
    	grid[r][c] = 0;
    	while (que.size())
    	{
    		r = que.front().first;
    		c = que.front().second;
    		que.pop();
    		if (r-1 >= 0 && grid[r-1][c])
    		{
    			grid[r-1][c] = 0;
    			que.push({r-1,c});
    			++area;
    		}
	    	if (c-1 >= 0 && grid[r][c-1])
	    	{
    			grid[r][c-1] = 0;
    			que.push({r,c-1});
    			++area;
	    	}
	    	if (r+1 < row && grid[r+1][c])
	    	{
    			grid[r+1][c] = 0;
    			que.push({r+1,c});
    			++area;
	    	}
	    	if (c+1 < col && grid[r][c+1])
	    	{
    			grid[r][c+1] = 0;
    			que.push({r,c+1});
    			++area;
	    	}
    	}
    	return area;
    }
};