//--- Q: 081. Search in Rotated Sorted Array II

//--- method 1: divide (binary search) O(n)
class Solution {
public:
    int search(vector<int>& nums, int target) {
    	bool find = false;
    	if (nums.empty()) return find;
        divide(nums, target, 0, nums.size()-1, find);
        return find;
    }
    void divide(vector<int> &nums, int target, int start, int end, bool &find)
    {
    	if (start < end)
    	{
    		int mid = (start+end)/2;
    		if (nums[mid] == target)
    			find = true;
    		else if (nums[start] == nums[mid])
    			divide(nums, target, start+1, end, find);
    		else if (nums[start] < nums[mid])
    		{
    			if (target >= nums[start] && target <= nums[mid])
    				divide(nums, target, start, mid, find);
    			else
    				divide(nums, target, mid+1, end, find);
    		}
    		else if (nums[mid+1] <= nums[end])
    		{
    			if (target >= nums[mid+1] && target <= nums[end])
    				divide(nums, target, mid+1, end, find);
    			else
    				divide(nums, target, start, mid, find);
    		}		
    	}
    	else
    		find = (nums[start] == target) ? true : false;
    }
};	