//--- Q: 0070. Climbing Stairs

//--- method 1: dp iteration
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp.back();
    }
};

//--- method 2: O(1) space
class Solution {
public:
    int climbStairs(int n) {
        int last1 = 1, last2 = 1;
        for (int i = 2; i <= n; ++i) {
            auto tmp = last1+last2;
            last2 = last1;
            last1 = tmp;
        }
        return last1;
    }
};