//--- Q: 0072. Edit Distance
//--- last written: 2023/07/04

//--- method 1: dp, O(n^2) space
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= m; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
            }
        }
        return dp[n][m];
    }
};

//--- method 2: dp, O(n) space
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> dp(m+1, 0);
        for (int j = 1; j <= m; ++j) {
            dp[j] = j;
        }
        int now, last;
        for (int i = 1; i <= n; ++i) {
            last = dp[0]++;
            for (int j = 1; j <= m; ++j) {
                now = dp[j];
                if (word1[i-1] == word2[j-1]) {
                    dp[j] = last;
                } else {
                    dp[j] = min(last, min(dp[j], dp[j-1])) + 1;
                }
                last = now;
            }
        }
        return dp[m];
    }
};
