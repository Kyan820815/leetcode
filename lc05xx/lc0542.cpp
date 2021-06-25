//--- Q: 542. 01 Matrix

//--- method 1: double pass
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(), INT_MAX-1));
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == 0)
                    res[i][j] = matrix[i][j];
                else
                {
                    if (i > 0)
                        res[i][j] = min(res[i][j], res[i-1][j]+1);
                    if (j > 0)
                        res[i][j] = min(res[i][j], res[i][j-1]+1);
                }
            }
        }
        for (int i = matrix.size()-1; i >= 0; --i)
        {
            for (int j = matrix[0].size()-1; j >= 0; --j)
            {
                if (res[i][j] == 1 || res[i][j] == 0)
                    continue;
                if (i < matrix.size()-1)
                    res[i][j] = min(res[i][j], res[i+1][j]+1);
                if (j < matrix[0].size()-1)
                    res[i][j] = min(res[i][j], res[i][j+1]+1);
            }
        }
        return res;
    }
};

//--- method 2: bfs iteration
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));
        queue<pair<int,int>> que;
        for (int i = 0; i < matrix.size(); ++i)
        {
        	for (int j = 0; j < matrix[0].size(); ++j)
        	{
        		if (matrix[i][j] == 0)
        		{
        			que.push({i,j});
    				res[i][j] = 0;
        		}
        	}
        }
        bfs(matrix, res, que);
        return res;
    }
    void bfs(vector<vector<int>> matrix, vector<vector<int>> &res, queue<pair<int,int>> &que)
    {
    	int row = matrix.size(), col = matrix[0].size();
    	while (que.size() != 0)
    	{
    		pair<int, int> now = que.front();
    		que.pop();
    		if (now.first-1 >= 0 && matrix[now.first-1][now.second] == 1 && res[now.first-1][now.second] > res[now.first][now.second]+1)
    		{
    			res[now.first-1][now.second] = res[now.first][now.second]+1;
    			matrix[now.first-1][now.second] = 0;
    			que.push({now.first-1, now.second});
    		}
    		if (now.first+1 < row && matrix[now.first+1][now.second] == 1 && res[now.first+1][now.second] > res[now.first][now.second]+1)
    		{
    			res[now.first+1][now.second] = res[now.first][now.second]+1;
    			matrix[now.first+1][now.second] = 0;
    			que.push({now.first+1, now.second});
    		}
    		if (now.second-1 >= 0 && matrix[now.first][now.second-1] == 1 && res[now.first][now.second-1] > res[now.first][now.second]+1)
    		{
    			res[now.first][now.second-1] = res[now.first][now.second]+1;
    			matrix[now.first][now.second-1] = 0;
    			que.push({now.first, now.second-1});
    		}
    		if (now.second+1 < col && matrix[now.first][now.second+1] == 1 && res[now.first][now.second+1] > res[now.first][now.second]+1)
    		{
    			res[now.first][now.second+1] = res[now.first][now.second]+1;
    			matrix[now.first][now.second+1] = 0;
    			que.push({now.first, now.second+1});
    		}
    	} 
    }
};

//--- method 3: dfs recursion
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));
        queue<pair<int,int>> que;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == 1 && !neibor_zero(matrix, i, j))
                    matrix[i][j] = INT_MAX;
            }
        }
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == 1)
                {
                    dfs(matrix, i, j);
                }
            }
        }
        return matrix;
    }
    bool neibor_zero(vector<vector<int>> &matrix, int r, int c)
    {
        if (r-1 >= 0 && matrix[r-1][c] == 0)
            return true;
        if (r+1 < matrix.size() && matrix[r+1][c] == 0)
            return true;
        if (c-1 >= 0 && matrix[r][c-1] == 0)
            return true;
        if (c+1 < matrix[0].size() && matrix[r][c+1] == 0)
            return true;
        return false;
    }
    void dfs(vector<vector<int>> &matrix, int r, int c)
    {
        if (r-1 >= 0 && matrix[r-1][c] > matrix[r][c]+1)
        {
            matrix[r-1][c] = matrix[r][c]+1;
            dfs(matrix, r-1, c);
        }   
        if (r+1 < matrix.size() && matrix[r+1][c] > matrix[r][c]+1)
        {
            matrix[r+1][c] = matrix[r][c]+1;
            dfs(matrix, r+1, c);
        }   
        if (c-1 >= 0 && matrix[r][c-1] > matrix[r][c]+1)
        {
            matrix[r][c-1] = matrix[r][c]+1;
            dfs(matrix, r, c-1);
        }   
        if (c+1 < matrix[0].size() && matrix[r][c+1] > matrix[r][c]+1)
        {
            matrix[r][c+1] = matrix[r][c]+1;
            dfs(matrix, r, c+1);
        }   
    }
};