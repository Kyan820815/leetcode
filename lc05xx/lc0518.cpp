//--- Q: 0518. Coin Change 2

//--- method 1: dp iteration
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (auto &coin: coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i-coin];
            }
        }
        return dp.back();
    }
};