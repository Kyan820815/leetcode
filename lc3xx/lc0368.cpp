//--- Q: 368. Largest Divisible Subset

//--- method 1: dp, space: O(n) 
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    	vector<int> output, result;
    	vector<int> dp(nums.size(), 1);
    	sort(nums.begin(), nums.end());
    	int max_idx = 0, max = 0;
    	int go;

    	if (nums.empty()) return vector<int>{};
    	output.resize(nums.size());
        for (int i = 0; i < nums.size(); ++i)
        {
        	output[i] = i;
        	int local_max = 0, local_idx = i;
        	for (int j = 0; j < i; ++j)
        	{
        		if (nums[i] % nums[j] == 0)
        		{
        			if (dp[j] > local_max)
        			{
        				local_max = dp[j];
        				local_idx = j;
        			}
        		}
        	}
        	dp[i] = local_max+1;
        	output[i] = local_idx;

        	if (dp[i] > max)
            {
                max = dp[i];
        		max_idx = i;
            }
        }
        go = max_idx;
        result.push_back(nums[go]);
        while(go != output[go])
        {
            go = output[go];
        	result.push_back(nums[go]);
        }
        return result;        	
    }
};


//--- method 2: dp, space: O(n^2) 
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    	vector<vector<int>> output_vec;
    	vector<int> dp(nums.size(), 1);
    	sort(nums.begin(), nums.end());
    	int max_idx = 0, max = 0;

    	if (nums.empty()) return vector<int>{};
    	output_vec.resize(nums.size());
        for (int i = 0; i < nums.size(); ++i)
        {
        	int local_max = 0, local_idx = i;
        	for (int j = 0; j < i; ++j)
        	{
        		if (nums[i] % nums[j] == 0)
        		{
        			if (dp[j] > local_max)
        			{
        				local_max = dp[j];
        				local_idx = j;
        			}
        		}
        	}
        	output_vec[i] = output_vec[local_idx];
        	output_vec[i].push_back(nums[i]);
        	dp[i] = local_max+1;

        	if (dp[i] > max)
        	{
        		max = dp[i];
        		max_idx = i;
        	}
        }
        return output_vec[max_idx];        	
    }
};

