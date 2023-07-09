//--- Q: 0096. Unique Binary Search Trees
//--- last written: 2023/07/09

//--- method 1: dp iteration
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp.back();
    }
};
