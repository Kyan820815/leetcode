//--- Q: 485. Max Consecutive Ones

//--- method 1: one pass
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    	int left = 0, right = 0;
    	int cnt = 0, max = INT_MIN;
    	while (right < nums.size())
    	{
    		if (nums[right++] == 1)
    		{
  				cnt++;
    			if (cnt > max)
    				max = cnt;
    		}
  			else
  				cnt = 0;
    	}
    	return max == INT_MIN ? 0 : max;
    }
};