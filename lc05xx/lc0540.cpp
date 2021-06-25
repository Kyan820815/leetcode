//--- Q: 540. Single Element in a Sorted Array

//--- method 1: O(logn)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    	int left = 0, right = nums.size()-1;
    	while (left < right)
    	{
    		int mid = (left+right)/2;
    		if (nums[mid-1] == nums[mid])
    		{
    			if ((right-mid) & 1 == 1)
    				left = mid+1;
    			else 
    				right = mid-2;
    		}
    		else if (nums[mid] == nums[mid+1])
    		{
    			if ((mid-left) & 1 == 1)
    				right = mid-1;
    			else
    				left = mid+2;
    		}
    		else
    			return nums[mid];
    	}
    	return nums[left];
    }
};