//--- 0279. Perfect Squares

//--- method 1-1: dp iteration
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j*j+i <= n; ++j) {
                dp[j*j+i] = min(dp[j*j+i], dp[i]+1);
            }
        }
        return dp[n];
    }
};