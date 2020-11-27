//--- Q: 096. Unique Binary Search Trees

//--- method 1: dp iteration
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        if (n <= 1) return 1;
        dp[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= (i-1); ++j)
            {
                dp[i] += dp[j]*dp[i-1-j];
            }
        }
        return dp[n];
    }
};

//--- method 2: dp recursion
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dfs(dp, n);
        return dp[n];
    }
    void dfs(vector<int> &dp, int n)
    {
        for (int i = 0; i <= n-1; ++i)
        {
            if (!dp[i])
                dfs(dp, i);
            if (!dp[n-i-1])
                dfs(dp, n-i-1);
            dp[n] += dp[i]*dp[n-i-1];
        }
    }
};