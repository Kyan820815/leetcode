//--- Q: 0034. Find First and Last Position of Element in Sorted Array
//--- last written: 2023/03/13

//--- method 1: double bainry search
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (!nums.size()) {
            return {-1,-1};
        }
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        if (nums[left] != target) {
            return {-1,-1};
        }
        int lv = left;
        left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] <= target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return {lv, right};
    }
};
