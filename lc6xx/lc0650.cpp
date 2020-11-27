//--- Q: 650. 2 Keys Keyboard

//--- method 1: dp iteration
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 0;
        for (int i = 2; i <= n; ++i) {
            dp[i] = i;
            for (int j = 2; j < i; ++j) {
                if (i%j == 0) {
                    dp[i] = dp[i/j]+j;
                    break;
                }
            }
        }
        return dp[n];
    }
};

//--- method 2: recursion
class Solution {
public:
    int minSteps(int n) {
        if (n == 1)
            return 0;
        for (int i = n-1; i >= 1; --i) {
            if (n%i == 0)
                return n/i + minSteps(i);
        }
        return n;
    }
};