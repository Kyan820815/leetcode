//--- Q: 1155. Number of Dice Rolls With Target Sum

//--- method 1: dp iteration
class Solution {
publclass Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9+7;
        if (n*k < target) {
            return 0;
        }
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            vector<int> tmp(target+1, 0);
            for (int j = 1; j <= k; ++j) {
                for (int l = j; l <= target; ++l) {
                    if (dp[l-j]) {
                        tmp[l] = (tmp[l] + dp[l-j]) % mod;
                    }
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
    int mod = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        if (n*k < target) {
            return 0;
        }
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return dfs(n, k, target, dp);
    }
    int dfs(int n, int k, int target, vector<vector<int>> &dp) {
        if (!n) {
            return !target ? 1 : 0;
        }
        if (dp[n][target] != -1) {
            return dp[n][target];
        }
        int cnt = 0;
        for (int i = 1; i <= k; ++i) {
            if (target-i >= 0) {
                cnt = (cnt+dfs(n-1, k, target-i, dp))%mod;
            }
        }
        return dp[n][target] = cnt;
    }
};
