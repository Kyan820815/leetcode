//--- Q: 0343. Integer Break

//--- method 1: dp iteration, O(n^2)
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                auto left = max(dp[j], j);
                auto right = max(dp[i-j], i-j);
                dp[i] = max(dp[i], left*right);
            }
        }
        return dp.back();
    }
};