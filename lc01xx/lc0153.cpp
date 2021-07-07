//--- Q: 0153. Find Minimum in Rotated Sorted Array

//--- method 1: binary search
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[left] <= nums[mid] && nums[mid+1] <= nums[right]) {
                return min(nums[left], nums[mid+1]);
            } else if (nums[left] <= nums[mid]) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};