//--- Q: 213. House Robber II

//--- method 1: 2 times pass
class Solution {
public:
    int rob(vector<int>& nums) {
        int oddMax = 0, evenMax = 0;
        int left, right;
        if (nums.size() == 0) return 0;
        else if (nums.size() == 1) return nums[0];
        
        for (int i = 1; i < nums.size(); ++i)
        {
        	if (i % 2 == 0)
        		evenMax = max(evenMax + nums[i], oddMax);
        	else
        		oddMax = max(oddMax + nums[i], evenMax);
        }
        right = max(oddMax, evenMax);
        
        oddMax = evenMax = 0;
        for (int i = 0; i < nums.size()-1; ++i)
        {
        	if (i % 2 == 0)
        		evenMax = max(evenMax + nums[i], oddMax);
        	else
        		oddMax = max(oddMax + nums[i], evenMax);
        }
        left = max(oddMax, evenMax);
        return max(left, right);
    }
};