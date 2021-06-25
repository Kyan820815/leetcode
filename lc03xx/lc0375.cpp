//--- Q: 375. Guess Number Higher or Lower II

//--- method 1: min-max iteration solution
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int i = 1; i <= n; ++i) {
            dp[i][i] = 0;
            for (int j = i-1; j >= 1; --j) {
                int minv = INT_MAX;
                for (int k = j+1; k < i; ++k) {
                    int left = dp[j][k-1];
                    int right = dp[k+1][i];
                    minv = min(minv, max(left, right)+k);
                }
                dp[j][i] = (i-j == 1) ? j : minv;
            }
        }
        return dp[1][n];
    }
};

//--- method 2: min-max recursion solution
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return dfs(1, n, dp);
    }
    int dfs(int start, int end, vector<vector<int>> &dp) {
        if (start == end) {
            return dp[start][end] = 0;
        } else if (start + 1 == end) {
            return dp[start][end] = start;
        }
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        int val = INT_MAX;
        for (int i = start+1; i < end; ++i) {
            val = min(val, i+max(dfs(start, i-1, dp), dfs(i+1, end, dp)));
        }
        return dp[start][end] = val;
    }
};