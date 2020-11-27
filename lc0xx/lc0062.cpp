//--- Q: 062. Unique Paths

//--- method 1: iterative, dp
class Solution {
public:
    int uniquePaths(int m, int n) {
    	vector<vector<int>> path(n,vector<int>(m));
    	path[0][0] = 1;
    	for (int i = 0; i < n; ++i)
    	{
    		for (int j = 0; j < m; ++j)
    		{
    			if (i == 0 || j == 0)
    				path[i][j] = 1;
    			else
    				path[i][j] = path[i-1][j]+path[i][j-1];
    		}
    	}
        return path[n-1][m-1];
    }
};

//--- method 2: dfs
class Solution {
public:
    int uniquePaths(int m, int n) {
    	vector<vector<int>> visit(n, vector<int>(m));
    	return dfs(m-1,n-1, visit);
    }
    int dfs(int m, int n, vector<vector<int>> &visit)
    {	
    	if (m == 0 && n == 0)
    	{
    		visit[0][0] = 1;
    		return visit[n][m];
    	} 
    	int left = 0, top = 0;
    	if (m-1 >= 0)
    		left = (visit[n][m-1] != 0) ? visit[n][m-1] : dfs(m-1,n,visit);
    	if (n-1 >= 0)
    		top = (visit[n-1][m] != 0) ? visit[n-1][m] : dfs(m,n-1,visit);
    	visit[n][m] = left+top;
    	return visit[n][m];
    }
};