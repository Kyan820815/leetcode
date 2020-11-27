//--- Q: 034. Find First and Last Position of Element in Sorted Array

//--- method 1: double bainry search
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	int left, right;
    	int left_id, right_id;
    	if (nums.size() == 0)
    		return vector<int>{-1, -1};

    	left = 0, right = nums.size()-1;	
    	while (left < right)
    	{
    		int mid = (left + right) / 2;
    		if (nums[mid] < target)
    			left = mid+1;
    		else 
    			right = mid;
    	}
    	left_id = left;
    	if (nums[left_id] != target)
    		left_id = -1;

    	left = 0, right = nums.size()-1;
    	while (left <= right)
    	{
    		int mid = (left + right) / 2;
    		if (nums[mid] <= target)
    			left = mid+1;
    		else 
    			right = mid-1;
    	}
    	right_id = left-1;
    	if (right_id < 0 || nums[right_id] != target)
    		right_id = -1;
    	
    	return {left_id, right_id};
    }
};