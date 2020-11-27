//--- Q: 153. Find Minimum in Rotated Sorted Array

//--- method 1: binary search
class Solution {
public:
    int findMin(vector<int>& nums) {
    	int n = nums.size();
        if (nums[0] <= nums[n-1])
        	return nums[0];
        int left = 0, right = n-1;
        while (left < right)
        {
        	int mid = (left+right)/2;
        	if (nums[left] <= nums[mid] && nums[mid+1] <= nums[right])
        		return min(nums[left], nums[mid+1]);
        	else if (nums[left] > nums[mid])
        		right = mid;
        	else if (nums[mid+1] >= nums[right])
        		left = mid+1;
        }
        return nums[left];
    }
};