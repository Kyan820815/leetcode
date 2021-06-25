//--- Q: 661. Image Smoother

//--- method 1: bit oeration with 16 bit for each element
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> dir = {{0,0}, {-1,0}, {1,0}, {0,-1}, {0,1}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};
        int n = M.size(), m = M[0].size();
        for (int i = 0; i < n; ++i)
        {
        	for (int j = 0; j < m; ++j)
        	{
        		int sum = 0, cnt = 0;
        		for (int k = 0; k < 9; ++k)
        		{
        			if (i+dir[k][0] < 0 || i+dir[k][0] >= n || j + dir[k][1] < 0 || j + dir[k][1] >= m)
        				continue;
        			sum += (M[i+dir[k][0]][j+dir[k][1]] & 0xFF);
        			++cnt;
        		}
        		M[i][j] |= (sum / cnt) << 8;
        	}
        }
        for (int i = 0; i < n; ++i)
        {
        	for (int j = 0; j < m; ++j)
        	{
        		M[i][j] >>= 8;
        	}
        }
        return M;
    }
};