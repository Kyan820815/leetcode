//--- Q: 0085. Maximal Rectangle

//--- method 1: dp iteration
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (!matrix.size()) return 0;
    	int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int maxv = 0;
        for (int i = 0; i < rows; ++i)
        {
        	for (int j = 0; j < cols; ++j)
        	{
        		if (matrix[i][j] == '0') continue;
        		if (j == 0)
        			dp[i][j] = 1;
        		else
        			dp[i][j] = dp[i][j-1] + 1;
        	}
        }
        for (int i = 0; i < rows; ++i)
        {
        	for (int j = 0; j < cols; ++j)
        	{
        		if (matrix[i][j] == '0') continue;
        		int minv = dp[i][j];
                maxv = max(maxv, dp[i][j]);
        		for (int k = i-1; k >= 0 && dp[k][j]; --k)
        		{
        			minv = min(dp[k][j], minv);
	        		maxv = max(maxv, minv * (i-k+1));
        		}
        	}
        }
        return maxv;
    }
};

//--- method 2: increasing stack implenmentaion
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (!matrix.size()) return 0;
    	int rows = matrix.size(), cols = matrix[0].size();
        vector<int> dp(cols, 0);
        int res = 0;
        for (int i = 0; i < rows; ++i)
        {
        	for (int j = 0; j < cols; ++j)
        	{
        		dp[j] = (matrix[i][j] == '0') ? 0 : ((i > 0 ) ? dp[j] : 0) + 1;
        	}
        	res = max(res, maxCap(dp));
        }
        return res;
    }
    int maxCap(vector<int> &height)
    {
    	stack<int> sk;
    	int maxv = 0;
    	height.push_back(0);
    	for (int i = 0; i < height.size(); ++i)
    	{
    		while (sk.size() && height[sk.top()] >= height[i])
    		{
    			int tmp = sk.top();
    			sk.pop();
    			maxv = max(maxv, height[tmp] * ((!sk.size()) ? i : i-sk.top()-1));
    		}
    		sk.push(i);
    	}
    	height.pop_back();
        return maxv;
    }
};
