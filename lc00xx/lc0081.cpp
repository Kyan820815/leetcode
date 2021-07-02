//--- Q: 0081. Search in Rotated Sorted Array II

//--- method 1: divide (binary search) O(n)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            while (left < mid && nums[left] == nums[mid]) {
                ++left;
            }
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target <= nums[mid]) {
                    right = mid;   
                } else {
                    left = mid+1;
                }
            } else {
                if (nums[mid+1] <= target && target <= nums[right]) {
                    left = mid+1;
                } else {
                    right = mid;
                }
            }
        }
        return nums[left] == target;
    }
};