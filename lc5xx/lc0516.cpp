//--- Q: 516. Longest Palindromic Subsequence

//--- method 1: dp iteration, O(n^2) space
class Solution {
public:
    int longestPalindromeSubseq(string s) {
    	int n = s.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int i = n-1; i >= 0; --i)
		{
            dp[i][i] = 1;
			for (int j = i+1; j < n; ++j)
			{
				if (s[i] == s[j])
					dp[i][j] = (j-i < 2 ? 0 : dp[i+1][j-1])+ 2;
				else
					dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
			}
		}
		return dp[0][n-1];
    }
};

//--- method 2: dp recursion, O(n^2) space
class Solution {
public:
    int longestPalindromeSubseq(string s) {
    	int n = s.size();
		vector<vector<int>> dp(n, vector<int>(n, -1));
		return recursion(s, dp, 0, n-1);
    }
    int recursion(string &s, vector<vector<int>> &dp, int left, int right)
    {
    	if (dp[left][right] != -1)
    		return dp[left][right];
    	if (left == right)
    	{
    		dp[left][right] = 1;
    		return dp[left][right];
    	}
    	if (s[left] == s[right])
            dp[left][right] = 2 + ((right-left < 2) ? 0 : recursion(s, dp, left+1, right-1));
    	else
    		dp[left][right] = max(recursion(s, dp, left+1, right), recursion(s, dp, left, right-1));
    	return dp[left][right];
    }
};