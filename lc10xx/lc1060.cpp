//--- Q: 1060. Missing Element in Sorted Array

//--- method 1: binary search
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (get(nums, mid) < k) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        if (left == nums.size()-1 && get(nums, left) < k) {
            return k-get(nums, left) + nums.back();
        } else {
            return k-get(nums, left-1)+nums[left-1];
        }
    }
    int get(vector<int> &nums, int idx) {
        return nums[idx]-nums[0]-idx;
    }
};