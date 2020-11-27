//--- Q: 628. Maximum Product of Three Numbers

//--- method 1: sort
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return max(nums[0]*nums[1]*nums.back(), nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3]);
    }
};

//--- method 2: O(n)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
    	vector<int> big, small;
    	int maxv = INT_MIN;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		if (big.size() < 3)
    		{
    			big.push_back(nums[i]);
    			maxv = max(maxv, nums[i]);
    		}
    		else
    		{
    			int bigid, bigmin = INT_MAX;
    			for (int j = 0; j < 3; ++j)
    			{
    				if (big[j] < bigmin)
    				{
    					bigmin = big[j];
    					bigid = j;
    				}
    			}
    			if (bigmin < nums[i])
    			{
    				big[bigid] = nums[i];
    				maxv = max(maxv, nums[i]);
    			}
    		}
    		if (small.size() < 2)
    			small.push_back(nums[i]);
    		else
    		{
    			if (small[0] < small[1] && small[1] > nums[i])
    				small[1] = nums[i];
    			else if (small[0] >= small[1] && small[0] > nums[i])
    				small[0] = nums[i];
    		}
    	}
    	return max(small[0]*small[1]*maxv, big[0]*big[1]*big[2]);
    }
};