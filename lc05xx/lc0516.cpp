//--- Q: 0516. Longest Palindromic Subsequence

//--- method 1: dp iteration, O(n^2) space
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size(), res = 1;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n-1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i+1 ; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + (j-i == 1 ? 0 : dp[i+1][j-1]);
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};