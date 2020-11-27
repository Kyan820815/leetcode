//--- Q: 334. Increasing Triplet Subsequence

//--- method 1: find number > second_min
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
    	int first_min, second_min;
    	first_min = second_min = INT_MAX;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		if (nums[i] <= first_min)
    			first_min = nums[i];
    		else if (nums[i] <= second_min)
    			second_min = nums[i];
    		else if (nums[i] > second_min)
    			return true;
    	}   
    	return false;
    }
};