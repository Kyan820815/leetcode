//--- Q: 0704. Binary Search

//--- method 1: O(logN) binary search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left, right;
        for (left = 0, right = nums.size()-1; left < right;) {
            int mid = left + (right-left)/2;
            if (nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return nums[left] == target ? left : -1;
    }
};