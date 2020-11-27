//--- Q: 647. Palindromic Substrings

//--- method 1: O(n) one pass
class Solution {
public:
    int countSubstrings(string s) {
    	int left, right, cnt = 0;
    	for (int i = 0; i < s.size(); ++i)
    	{
    		left = right = i;
    		while(s[left] == s[right])
    		{
    			cnt++;
    			right++;
    		}
    		left--;
    		while(left >= 0 && s[left] == s[right])
    		{
    			left--;
    			right++;
    			cnt++;
    		}
    	}
    	return cnt;
    }
};

//--- method 2: dp, O(n^2)
class Solution {
public:
    int countSubstrings(string s) {
    	vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    	int n = s.size(), res = 0;
    	for (int i = n-1; i >= 0; --i)
    	{
    		for (int j = i; j < n; ++j)
    		{
    			if (s[i] == s[j] && (j-i < 2 || dp[i+1][j-1]))
    			{
    				dp[i][j] = 1;
    				res++;
    			}
    		}
    	}
    	return res;
    }
};
