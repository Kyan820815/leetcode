//--- Q: 1143. Longest Common Subsequence

//--- method 1: O(n^2) space
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
    	int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i)
        {
        	for (int j = 0; j < m; ++j)
        	{
        		if (text1[i] == text2[j])
        			dp[i][j] = max(((i == 0 || j == 0) ? 0 : dp[i-1][j-1]) + 1, dp[i][j]);
        		else
        			dp[i][j] = max((i == 0 ? 0 : dp[i-1][j]), (j == 0 ? 0 : dp[i][j-1]));
        	}
        }
        return dp[n-1][m-1];
    }
};

//--- method 2: O(n) space
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
    	int n = text1.size(), m = text2.size();
        vector<int> dp(m, 0);
        int last, pre;
        for (int i = 0; i < n; ++i)
        {
        	for (int j = 0; j < m; ++j)
        	{
        		int last = dp[j];
        		if (text1[i] == text2[j])
        			dp[i][j] = max(((i == 0 || j == 0) ? 0 : pre) + 1, dp[j]);
        		else
        			dp[i][j] = max((i == 0 ? 0 : dp[j]), (j == 0 ? 0 : dp[j-1]));
        		pre = last;
        	}
        }
        return dp[n-1][m-1];
    }
};