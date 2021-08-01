//--- Q: 0540. Single Element in a Sorted Array

//--- method 1: binary search
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left, right, n = nums.size();
        for (left = 0, right = n-1; left < right;) {
            int mid = left + (right-left)/2;
            if (nums[mid] == nums[mid+1]) {
                if ((right-mid)%2 == 0) {
                    left = mid+2;
                } else {
                    right = mid-1;
                }
            } else {
                if ((right-mid)%2 == 0) {
                    right = mid;
                } else {
                    left = mid+1;                    
                }
            }
        }
        return nums[left];
    }
};