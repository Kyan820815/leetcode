//--- Q: 35. Search Insert Position

//--- method 1: linear search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i)
        	if (nums[i] >= target) return i;
        return nums.size();
    }
};

//--- method 2: binary search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return nums[left] >= target ? left : left+1;
    }
};