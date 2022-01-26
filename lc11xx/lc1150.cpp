//--- Q: 1150. Check If a Number Is Majority Element in a Sorted Array

//--- method 1: binary search
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, lv, rv;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return nums[left] == target && left+nums.size()/2 < nums.size() && nums[left+nums.size()/2] == target;
    }
};