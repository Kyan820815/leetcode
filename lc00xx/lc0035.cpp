//--- Q: 0035. Search Insert Position
//--- last written: 2023/06/09

//--- method 1: binary search
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
