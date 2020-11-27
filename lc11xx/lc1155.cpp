//--- Q: 1155. Number of Dice Rolls With Target Sum

//--- method 1: dp iteration
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int M = 1e9+7;
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        if (target - d*f > 0) return 0;
		for (int i = 0; i < d; ++i)
		{
            vector<int> tmp(target+1, 0);
            for (int k = 1; k <= target; ++k)
            {
                for (int j = 1; j <= min(f,k); ++j)
                {
                    tmp[k] = (tmp[k]+dp[k-j])%M;
                }
            }
            dp = tmp;
		}
        return dp[target];
    }
};

//--- method 1-2: dp iteration
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        if (d*f < target) {
            return 0;
        }
        int mod = 1e9 + 7;
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 0; i < d; ++i) {
            vector<int> tmp(target+1, 0);
            for (int j = 1; j <= f; ++j) {
                for (int k = 0; k+j <= target; ++k) {
                    tmp[k+j] = (tmp[k+j] + dp[k]) % mod;
                }
            }
            dp = tmp;
        }
        return dp[target];
    }
};

//--- method 2: dp recursion
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int M = 1e9+7;
        vector<vector<int>> dp(d+1, vector<int>(target+1, -1));
        if (target - d*f > 0) return 0;
        return dfs(d, target, f, dp);
    }
    int dfs(int times, int amount, int f, vector<vector<int>> &dp)
    {
    	int cnt = 0, M = 1e9+7;
    	if (amount == 0 && times == 0) return 1;
    	if (dp[times][amount] != -1)
    		return dp[times][amount];

    	for (int i = 1; i <= min(f,amount) && times > 0; ++i)
    		cnt = (cnt + dfs(times-1, amount-i, f, dp)) % M;
    	dp[times][amount] = cnt;
    	return cnt;
    }
};
