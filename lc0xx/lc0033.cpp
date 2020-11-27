//--- Q: 033. Search in Rotated Sorted Array

//--- method 1: divide (binary search) logN
class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int idx = -1;
    	if (nums.empty()) return idx;
        divide(nums, target, 0, nums.size()-1, idx);
        return idx;
    }
    void divide(vector<int> &nums, int target, int start, int end, int &idx)
    {
    	if (start < end)
    	{
    		int mid = (start+end)/2;
    		if (nums[mid] == target)
    			idx = mid;
    		else if (nums[start] <= nums[mid])
    		{
    			if (target >= nums[start] && target <= nums[mid])
    				divide(nums, target, start, mid, idx);
    			else
    				divide(nums, target, mid+1, end, idx);
    		}
    		else if (nums[mid+1] <= nums[end])
    		{
    			if (target >= nums[mid+1] && target <= nums[end])
    				divide(nums, target, mid+1, end, idx);
    			else
    				divide(nums, target, start, mid, idx);
    		}		
    	}
    	else
    	{
    		if (nums[start] == target) 
    			idx = start;
    		else 
    			idx = -1;
    	}
    }
};	