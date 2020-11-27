//--- Q: 375. Guess Number Higher or Lower II

//--- method 1: min-max solution
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int i = 2; i <= n; ++i)
        {
        	for (int j = i-1; j >= 1; --j)
        	{
        		int minv = INT_MAX;
        		for (int k = j+1; k < i; ++k)
        		{
        			int maxv = k + max(dp[j][k-1], dp[k+1][i]);
        			minv  = min(minv, maxv);
        		}
        		dp[j][i] = (j+1 == i) ? j : minv;
        	}
        }
        return dp[1][n];
    }
};