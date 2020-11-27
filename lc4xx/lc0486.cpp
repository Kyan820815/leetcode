//--- Q: 486. Predict the Winner

//--- method 1: dfs recursion
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return dfs(nums, 0, 0, 1);
    }
    bool dfs(vector<int> &nums, int sum1, int sum2, int player)
    {
    	if (nums.size() == 1)
    	{
    		if (player == 1)
    			return sum1+nums[0] >= sum2;
    		else
    			return sum1 < sum2 + nums[0];
    	}

    	vector<int> head = nums;
    	vector<int> end = nums;
    	head.pop_back();
    	end.erase(end.begin());

    	if (player == 1)
    		return !dfs(head, sum1+nums.back(), sum2, 2) || !dfs(end, sum1+nums.front(), sum2, 2);
    	else
    		return !dfs(head, sum1, sum2+nums.back(), 1) || !dfs(end, sum1, sum2+nums.front(), 1);
    }
};

//--- method 2: dp recursion
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
    	vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        if (nums.size() == 0) return true;
        return dfs(nums, 0, nums.size()-1, dp) >= 0;
    }
    int dfs(vector<int> &nums, int start, int end, vector<vector<int>> &dp)
    {
    	if (dp[start][end] == -1)
			dp[start][end] = (start == end) ? nums[start] : max(nums[start]-dfs(nums, start+1, end, dp), nums[end]-dfs(nums, start, end-1, dp));

    	return dp[start][end];
    }
};

//--- method 3: dp iteration
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
    	vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));

    	for (int len = 1; len <= nums.size(); ++len)
    	{
    		for (int i = 0; i <= nums.size()-len; ++i)
    		{
    			int j = i+len-1;
    			dp[i][j] = (i == j) ? nums[i] : max(nums[j] - dp[i][j-1], nums[i]-dp[i+1][j]);
    		}
    	}
    	return dp[0][nums.size()-1] >= 0;
    }
};