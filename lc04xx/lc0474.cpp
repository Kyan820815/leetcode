//--- Q: 0474. Ones and Zeroes

//--- method 1: dp top down
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (auto &str: strs) {
            int ones = 0;
            for (auto &ch: str) {
                ones += ch == '1';
            }
            int zeros = str.size()-ones;
            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

//--- method 2: dp bottom up
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (auto &str: strs) {
            int ones = 0;
            for (auto &ch: str) {
                ones += ch == '1';
            }
            int zeros = str.size()-ones;
            vector<vector<int>> tmp = dp;
            for (int i = 0; i <= m-zeros; ++i) {
                for (int j = 0; j <= n-ones; ++j) {
                    tmp[i+zeros][j+ones] = max(tmp[i+zeros][j+ones], dp[i][j]+1);
                }
            }
            dp = tmp;
        }
        return dp[m][n];
    }
};