//--- Q: 704. Binary Search

//--- method 1: O(logN) binary search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left < right)
        {
        	int mid = (left+right) / 2;
        	if (nums[mid] < target)
        		left = mid+1;
        	else right = mid;
        }
        return (nums[left] == target) ? left : -1;
    }
};