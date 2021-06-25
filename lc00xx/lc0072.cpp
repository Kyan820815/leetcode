//--- Q: 072. Edit Distance

//--- method 1: dp, O(n^2) space
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for (int i = 1; i <= n1; ++i) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n2; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j-1]+1, min(dp[i-1][j]+1, dp[i][j-1]+1));
                }
            }
        }
        return dp[n1][n2];
    }
};

//--- method 2: dp, O(n) space
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<int> dp(n2+1, 0);
        for (int j = 1; j <= n2; ++j) {
            dp[j] = j;
        }
        for (int i = 1; i <= n1; ++i) {
            int last = dp[0], now;
            dp[0] = i;
            for (int j = 1; j <= n2; ++j) {
                now = dp[j];
                if (word1[i-1] == word2[j-1]) {
                    dp[j] = last;
                } else {
                    dp[j] = min(last+1, min(dp[j]+1, dp[j-1]+1));
                }
                last = now;
            }
        }
        return dp.back();
    }
};