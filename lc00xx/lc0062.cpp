//--- Q: 0062. Unique Paths
//--- last written: 2023/07/02

//--- method 1: iterative, dp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 1; i < m; ++i) {
            dp[i][0] += dp[i-1][0];
        }
        for (int j = 1; j < n; ++j) {
            dp[0][j] += dp[0][j-1];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] += dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

//--- method 2: dfs with memo
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(m-1, n-1, dp);
    }
    int dfs(int i, int j, vector<vector<int>> &dp) {
        if (!i && !j) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int v = 0;
        if (i) {
            v += dfs(i-1, j, dp);
        }
        if (j) {
            v += dfs(i, j-1, dp);
        }
        return dp[i][j] = v;
    }
};
