//--- Q: 322. Coin Change

//--- method 0: dp iteration, my version
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= amount; ++i)
        {
            for (int j = 0; j < coins.size(); ++j)
                if (coins[j] != INT_MAX && i+coins[j] <= amount && dp[i] != INT_MAX)
                    dp[i+coins[j]] = min(dp[i+coins[j]], dp[i]+1);
        }
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};

//--- method 1: dp-1, iteration, better
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
		for (int i = 1; i <= amount; ++i)
        {
        	int min = INT_MAX;
        	for (int j = 0; j < coins.size(); ++j)
        	{
        		if (i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX)
        		{
        			if (min > dp[i-coins[j]]+1)
        				min = dp[i-coins[j]]+1;
        		}
        	}
        	dp[i] = min;
        }
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};

//--- method 2: dp-2 iteration
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); ++i)
		{
			for (int j = coins[i]; j <= amount; ++j)
			{
				if (dp[j-coins[i]] != INT_MAX)
					dp[j] = min(dp[j], dp[j-coins[i]]+1);
			}
		}
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};

//--- method 3: dp-3 recursion
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
     	vector<int> dp(amount+1, INT_MAX);
     	dp[0] = 0;
     	dfs(coins, dp, amount);
     	return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
    void dfs(vector<int> &coins, vector<int> &dp, int amount)
    {
    	int min = INT_MAX;
    	if (dp[amount] != INT_MAX)
    		return;
    	for (int i = 0; i < coins.size(); ++i)
    	{
    		if (amount-coins[i] >= 0)
    		{
    			if (dp[amount-coins[i]] == INT_MAX)
    				dfs(coins, dp, amount-coins[i]);
    			if (dp[amount-coins[i]] != INT_MAX && dp[amount-coins[i]] >= 0)
    			{
    				if (min > dp[amount-coins[i]]+1)
    					min = dp[amount-coins[i]]+1;
    			}
    		}
    	}
    	if (min == INT_MAX)
    		min = -1;
    	dp[amount] = min;
    }
};