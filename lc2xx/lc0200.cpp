//--- Q: 200. Number of Islands

//--- method 1: dfs
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    	if (grid.empty()) return 0;
        int row = grid.size(), col = grid[0].size();
    	int island = 0;
    	for (int i = 0; i < row; ++i)
    	{
    		for (int j = 0; j < col; ++j)
    		{
    			if (grid[i][j] == '1')
    			{
    				island++;
    				dfs(grid, row, col, i, j);
    			}
    		}
    	}
    	return island;

    }
    void dfs(vector<vector<char>> &grid, int row, int col, int r, int c)
    {
    	if (r < 0 || r >= row || c < 0 || c >= col)
    		return;
    	if (grid[r][c] == '1')
    		grid[r][c] = '2';
    	else return;
    	dfs(grid, row, col, r-1, c);
    	dfs(grid, row, col, r+1, c);
    	dfs(grid, row, col, r, c-1);
    	dfs(grid, row, col, r, c+1);
    }
};

//--- method 2: bfs
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    	if (grid.empty()) return 0;
        int row = grid.size(), col = grid[0].size();
    	int island = 0;
    	for (int i = 0; i < row; ++i)
    	{
    		for (int j = 0; j < col; ++j)
    		{
    			if (grid[i][j] == '1')
    			{
    				island++;
    				bfs(grid, row, col, i, j);
    			}
    		}
    	}
    	return island;
    }
    void bfs(vector<vector<char>> &grid, int row, int col, int r, int c)
    {
    	queue<int> que;
        vector<int> dirX{-1, 0, 1, 0}, dirY{0, 1, 0, -1};
    	int now, nr, nc;
    	que.push(r*col+c);
    	grid[r][c] = '2';
    	while(!que.empty())
    	{
    		now = que.front();
    		que.pop();
    		nr = now / col;
    		nc = now % col;
    		for (int k = 0; k < 4; ++k) {
	            int x = nr + dirX[k], y = nc + dirY[k];
	            if (x < 0 || x >= row || y < 0 || y >= col || grid[x][y] != '1') continue;
	            grid[x][y] = '2';
	            que.push(x * col + y);
	        }
    	}
    }
};