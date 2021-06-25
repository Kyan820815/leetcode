//--- 279. Perfect Squares

//--- method 1-1: dp iteration
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(1, INT_MAX);
        dp[0] = 0;

        while(dp.size() <= n)
        {
            int val = INT_MAX;
            for (int i = 1; i*i <= dp.size(); ++i)
            {
                val = min(val, dp[dp.size()-i*i]+1);                
            }
            dp.push_back(val);
        }
        return dp[n];
    }
};

//--- method 1-1: dp iteration, my version
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j*j <= i; ++j)
            {
                dp[i] = min(dp[i], dp[i-j*j]+1);                
            }
        }
        return dp[n];
    }
};

//--- method 1-2: dp iteration
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i)
        {
            for (int j = 1; i+j*j <= n; ++j)
            {
                dp[i+j*j] = min(dp[i+j*j], dp[i]+1);
            }
        }
        return dp[n];
    }
};

//--- method 2: dp recursion
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
    	dfs(n, dp);
    	return dp[n];
    }
    void dfs(int n, vector<int> &dp)
    {
    	for (int i = 1; i*i <= n; ++i)
        {
            int nums = i*i;
            if ((n-nums == 0) || dp[n-nums] != INT_MAX)
                dp[n] = min(dp[n], dp[n-nums]+1);
            else
            {
                dfs(n-nums, dp);
                dp[n] = min(dp[n], dp[n-nums]+1);
            }
        }
    }
};