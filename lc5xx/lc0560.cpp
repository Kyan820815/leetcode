//--- Q: 560. Subarray Sum Equals K

//--- method 1: dp with map, prefix sum
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    	int sum = 0, res = 0;
    	unordered_map<int,int> dp;
    	dp[0] = 1;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		sum += nums[i];
    		res += dp[sum-k];
    		dp[sum]++;
    	}

    	return res;
    }
};

//--- method 2: O(n^2)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    	int sum = 0, res = 0;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		sum += nums[i];
    		if (tmp == k)
    			res++;
    		int tmp = sum;
    		for (int j = 0; j < i; ++j)
    		{
    			tmp -= nums[j];
    			if (tmp == k)
    				res++;
    		}
    	}
    	return res;
    }
};