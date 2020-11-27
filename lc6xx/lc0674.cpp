//--- Q: 674. Longest Continuous Increasing Subsequence

//--- method 1: linear processing
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
    	int maxl = INT_MIN, len = 1;
        if (!nums.size()) return 0;
    	for (int i = 1; i < nums.size(); ++i)
    	{
    		if (nums[i] > nums[i-1]) ++len;
    		else
    		{
    			maxl = max(maxl, len);
    			len = 1;
    		}
    	}
    	maxl = max(maxl, len);
    	return maxl;
    }
};