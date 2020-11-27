//--- Q: 518. Coin Change 2

//--- method 1: dp iteration
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); ++i)
        {
        	for (int j = coins[i]; j <= amount; ++j)
        	{
        		dp[j] += dp[j-coins[i]];
        	}
        }
        return dp[amount];
    }
};

//--- method 2: dfs recursion
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1, vector<int>(coins.size(), -1));
        if (coins.size() == 0 && amount == 0) return 1;
        return dfs(coins, dp, 0, amount);
    }
    int dfs(vector<int> &coins,vector<vector<int>> &dp, int start, int amount)
    {
        int cnt = 0;
        if (amount < 0 || start == coins.size())
            return 0;
    	if (dp[amount][start] != -1)
            return dp[amount][start];
        if (amount == 0)
            return 1;

        cnt = dfs(coins, dp, start, amount-coins[start]) + dfs(coins, dp, start+1, amount);
        dp[amount][start] = cnt;
        return cnt;
    }
};