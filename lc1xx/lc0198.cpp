//--- Q: 198. House Robber

//--- method 1: dp, O(n), space O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int oddMax = 0, evenMax = 0;
    
		for (int i = 0; i < nums.size(); ++i)
		{
			if (i % 2 == 0)
				evenMax = max(oddMax, evenMax + nums[i]);
			else
				oddMax = max(evenMax, oddMax + nums[i]);
		}
        return max(oddMax, evenMax);
    }
};

//--- method 2: dp, O(n), space O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
    	vector<int> dp(nums.size(), 0);
        int global_max = INT_MIN;
        if (nums.size() == 0) return 0;
        else if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return max(nums[0], nums[1]);
    
        dp[0] = nums[0], dp[1] = max(dp[0],nums[1]);
		for (int i = 2; i < nums.size(); ++i)
        	dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        return dp[nums.size()-1];
    }
};

//--- method 3: dp, O(n^2), space O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
    	vector<int> dp(nums.size(), 0);
        int global_max = INT_MIN;
        if (nums.size() == 0) return 0;
        else if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return max(nums[0], nums[1]);
    
        dp[0] = nums[0], dp[1] = nums[1];
        global_max = max(dp[0], dp[1]);
		for (int i = 2; i < nums.size(); ++i)
        {
        	int locoal_max = INT_MIN;
        	for (int j = i-2; j >= 0; --j)
        	{
        		if (dp[j] > locoal_max)
        			locoal_max = dp[j];
        	}
        	dp[i] = locoal_max + nums[i];
        	if (global_max < dp[i])
        		global_max = dp[i];
        }
        return global_max;
    }
};