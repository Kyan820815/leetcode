//--- Q: 0983. Minimum Cost For Tickets

//--- method 1: one day by one day
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, 0);
        for (auto &day: days) {
            dp[day] = 1;
        }
        for (int i = 1; i <= 365; ++i) {
            if (dp[i]) {
                dp[i] = dp[i-1] + costs[0];
                dp[i] = min(dp[i], (i >= 7 ? dp[i-7] : 0) + costs[1]);
                dp[i] = min(dp[i], (i >= 30 ? dp[i-30] : 0) + costs[2]);
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp.back();
    }
};