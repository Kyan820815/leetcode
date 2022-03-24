//--- Q: 1230. Toss Strange Coins

//--- method 1: O(nk) space
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<vector<double>> dp(n+1, vector<double>(target+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            int limit = min(target, i);
            for (int j = 0; j <= limit; ++j) {
                dp[i][j] = dp[i-1][j]*(1-prob[i-1]) + (j ? dp[i-1][j-1]*(prob[i-1]) : 0);
            }
        }
        return dp[n][target];
    }
};

//--- method 2: O(k) space
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<double> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            int limit = min(target, i);
            double pre = dp[0], now;
            for (int j = 0; j <= limit; ++j) {
                now = dp[j];
                dp[j] = dp[j]*(1-prob[i-1]) + (j ? pre*prob[i-1] : 0);
                pre = now;
            }
        }   
        return dp[target];
    }
};