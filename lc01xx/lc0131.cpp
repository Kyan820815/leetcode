//--- Q: 131. Palindrome Partitioning

//--- method 1: dfs with pre-computed palidrome, better
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> res_v;
        vector<vector<string>> res;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = s.size()-1; i >= 0; --i)
        {
        	for (int j = i; j < s.size(); ++j)
        	{
        		if ((j-i < 2 || dp[i+1][j-1]) && s[i] == s[j])
        			dp[i][j] = 1;
        	}
        }
        dfs(s, 0, dp, res_v, res);
        return res;
    }
    void dfs(string s, int start, vector<vector<int>> &dp, vector<string> &res_v, vector<vector<string>> &res)
    {
    	if (start == s.size())
    	{
    		res.push_back(res_v);
			return;    	 	
    	}
    	//--- cut
    	for (int i = start; i < s.size(); ++i)
    	{
	    	string s_str = s.substr(start, i-start+1);
    		if (dp[start][i] == 0) continue;
	    	res_v.push_back(s_str);
    		dfs(s, i+1, dp, res_v, res);
	    	res_v.pop_back();
    	}
    }
};

//--- method 2: dfs with check palidrome every time 
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> res_v;
        vector<vector<string>> res;
        dfs(s, 0, res_v, res);
        return res;
    }
    void dfs(string s, int start, vector<string> &res_v, vector<vector<string>> &res)
    {
    	if (start == s.size())
    	{
    		res.push_back(res_v);
			return;    	 	
    	}
    	//--- cut
    	for (int i = start; i < s.size(); ++i)
    	{
	    	string s_str = s.substr(start, i-start+1);
	    	if (!isPal(s_str)) continue;
	    	res_v.push_back(s_str);
    		dfs(s, i+1, res_v, res);
	    	res_v.pop_back();
    	}
    }
    bool isPal(string s)
    {
    	for (int i = 0; i < s.size()/2; ++i)
    	{
    		if (s[i] != s[s.size()-i-1])
    			return false;
    	}
    	return true;
    }
};