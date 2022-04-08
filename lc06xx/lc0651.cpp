//--- Q: 0651. 4 Keys Keyboard

//--- method 1: dp iteration
class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = i;
            for (int j = i-3; j >= 1; --j) {
                dp[i] = max(dp[i], dp[j] + (i-j-2)*dp[j]);
            }
        }
        return dp[n];
    }
};

//--- method 2: find pattern\class Solution {
public:
    int maxA(int n) {
        if (n <= 6) {
            return n;
        }
        vector<int> dp(n+1, 0);
        for (int i = 1; i <= 6; ++i) {
            dp[i] = i;
        }
        for (int i = 7; i <= n; ++i) {
            dp[i] = max(dp[i-4]*3, dp[i-5]*4);
        }
        return dp[n];
    }
};