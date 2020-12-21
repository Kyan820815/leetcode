//--- Q: 1060. Missing Element in Sorted Array

//--- method 1: binary search
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (func(nums, mid) < k) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        if (k > func(nums, left)) {
            return nums[left] + k-func(nums, left);
        } else {
            return nums[left-1] + k-func(nums, left-1);
        }
    }
    int func(vector<int> &nums, int idx) {
        return idx ? nums[idx]-nums[0]-idx : 0;
    }
};