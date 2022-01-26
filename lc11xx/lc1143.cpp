//--- Q: 1143. Longest Common Subsequence

//--- method 1: O(n) space
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int> dp(m, 0);
        for (int i = 0; i < n; ++i) {
            int prev = 0;
            for (int j = 0; j < m; ++j) {
                int now = dp[j];
                if (text1[i] == text2[j]) {
                    dp[j] = prev+1;
                } else {
                    dp[j] = max(dp[j], j ? dp[j-1] : 0);
                }
                prev = now;
            }
        }
        return dp.back();
    }
};