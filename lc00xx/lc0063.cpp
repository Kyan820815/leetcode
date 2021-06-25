//--- Q: 063. Unique Paths II

//--- method 1: dfs recursion
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> path(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(),-1));
        return dfs(obstacleGrid, path, obstacleGrid.size()-1, obstacleGrid[0].size()-1);
    }
    int dfs(vector<vector<int>>& obstacleGrid, vector<vector<int>> &path, int i, int j)
    {
    	if (obstacleGrid[i][j] == 1)
    	{
    		path[i][j] = 0;
    		return path[i][j];
    	}
    	if (path[i][j] != -1) return path[i][j];

    	if (i-1 >= 0 && j-1>=0)
    	   path[i][j] = dfs(obstacleGrid, path, i-1, j) + dfs(obstacleGrid, path, i, j-1);
    	else if (i-1 >= 0)
    		path[i][j] = dfs(obstacleGrid, path, i-1, j);
    	else if (j-1 >= 0)
    		path[i][j] = dfs(obstacleGrid, path, i, j-1);
    	else path[i][j] = 1;
    	return path[i][j];
    }
};

//--- method 2: dp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        vector<vector<long long int>> path(row, vector<long long int>(col,0));
        
        if (!obstacleGrid[0][0])
        	path[0][0] = 1;
       	for (int i = 0; i < row; ++i)
       	{
       		for (int j = 0; j < col; ++j)
       		{
       			if (obstacleGrid[i][j] == 1) continue;
       			else if (i == 0 || j == 0)
       			{
       				if (j != 0)
       					path[i][j] = path[i][j-1];
       				else if (i != 0)
       					path[i][j] = path[i-1][j];
       			}
       			else
       				path[i][j] = path[i-1][j] + path[i][j-1];
       		}
       	}
       	return path[row-1][col-1];
    }
};