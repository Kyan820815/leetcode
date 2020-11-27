//--- Q: 494. Target Sum

//--- method 1: recursion dp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
    	vector<unordered_map<int, int>> dp(nums.size()+1);
    	if (S > 1000) return 0;
	    dfs(nums, dp, S, nums.size());
	    return dp[nums.size()][S];
    }
    void dfs(vector<int>& nums, vector<unordered_map<int, int>> &dp, int sum, int idx)
    {
    	if (idx == 0)
    	{
            dp[idx][sum] = (sum == 0) ? 1 : 0;
    		return;
    	}
    	if (dp[idx].count(sum))
    		return;
    	dfs(nums, dp, sum + nums[idx-1], idx - 1);
	    dfs(nums, dp, sum - nums[idx-1], idx - 1);
	    dp[idx][sum] = dp[idx-1][sum+nums[idx-1]] + dp[idx-1][sum-nums[idx-1]]; 
    }
};

//--- method 2-1: iteration dp, space: O(n^2)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
    	vector<unordered_map<int, int>> dp(nums.size()+1);
    	if (S > 1000) return 0;
    	dp[0][0] = 1;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		for (auto &a : dp[i])
    		{
    			int sum = a.first;
    			int cnt = a.second;
    			dp[i+1][sum+nums[i]] += cnt;
    			dp[i+1][sum-nums[i]] += cnt;
    		}
    	}
	   	return dp[nums.size()][S];
    }
};

//--- method 2-2: iteration dp, space: O(n)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
    	unordered_map<int, int> dp;
    	if (S > 1000) return 0;
    	dp[0] = 1;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		unordered_map<int, int> t;
    		for (auto &a : dp)
    		{
    			int sum = a.first;
    			int cnt = a.second;
    			t[sum+nums[i]] += cnt;
    			t[sum-nums[i]] += cnt;
    		}
    		dp = t;
    	}
	   	return dp[S];
    }
};

//--- method 3: partitial sum
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
    	int sum = 0, half_sum;
    	vector<int> dp;
        
        if (S > 1000)
            return 0;
    	for (int i = 0; i < nums.size(); ++i)
    		sum += nums[i];
        if ((sum+S) % 2 == 1)
            return 0;
        
        half_sum = (sum+S)/2;
        dp.resize(half_sum+1);
    	dp[0] = 1;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		for (int j = half_sum; j >= nums[i]; --j)
    				dp[j] += dp[j-nums[i]];
    	}
	   	return dp[half_sum];
    }
};