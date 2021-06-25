//--- Q: 983. Minimum Cost For Tickets

//--- method 1: one day by one day
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < days.size(); ++i)
        	dp[days[i]] = 0;
    	for (int i = 1; i < 366; ++i)
    	{
    		if (dp[i] == INT_MAX)
    			dp[i] = dp[i-1];
    		else
    		{
    			int cur = dp[i-1] + costs[0];
    			cur = min(cur, dp[max(0, i-7)] + costs[1]);
    			cur = min(cur, dp[max(0, i-30)] + costs[2]);
    			dp[i] = cur;
    		}
    	}
    	return dp[days[days.size()-1]];
    }
};
