//--- Q: 0583. Delete Operation for Two Strings

//--- method 2: dp iteration, O(nm) space
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1]+1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return word1.size()+word2.size()-2*dp[n1][n2];
    }
};

//--- method 1: dp iteration, O(n) space
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<int> dp(n2, 0);
        for (int i = 0; i < n1; ++i) {
            int last = 0, now;
            for (int j = 0; j < n2; ++j) {
                now = dp[j];
                if (word1[i] == word2[j]) {
                    dp[j] = last+1;
                } else {
                    dp[j] = max(dp[j], j ? dp[j-1] : 0);
                }
                last = now;
            }
        }
        return word1.size()+word2.size()-2*dp.back();
    }
};