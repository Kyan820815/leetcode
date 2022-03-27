//--- Q: 0464. Can I Win

//--- method 1: dp, bit manipulation
class Solution {
public:
    vector<int> dp;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1+maxChoosableInteger)*maxChoosableInteger/2 < desiredTotal)  {
            return false;
        }
        dp.resize(1<<21, -1);
        return dfs(0, maxChoosableInteger, desiredTotal);
    }
    int dfs(int choose, int option, int sum) {
        if (dp[choose] != -1) {
            return dp[choose];
        }
        for (int i = 1; i <= option; ++i) {
            if (choose & (1<<i)) {
                continue;
            }
            if (sum-i <= 0 || !dfs(choose|(1<<i), option, sum-i)) {
                return dp[choose] = 1;
            }
        }
        return dp[choose] = 0;
    }
};