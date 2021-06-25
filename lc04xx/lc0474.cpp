//--- Q: 474. Ones and Zeroes

//--- method 1: dp
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int zeros, ones;

        for (int i = 0; i < strs.size(); ++i)
        {
        	zeros = ones = 0;
        	for (int j = 0; j < strs[i].size(); ++j)
        	{
        		if (strs[i][j] == '0') zeros++;
        		else ones++;
        	}
        	for (int j = m; j >= zeros; --j)
        	{
        		for (int k = n; k >= ones; --k)
        		{
        			dp[j][k] = max(dp[j][k], dp[j-zeros][k-ones]+1);
        		}
        	}
        }

        return dp[m][n];
    }
};