//--- Q: 0961. N-Repeated Element in Size 2N Array

//--- method 1: find pattern
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1] || nums[i] == nums[i-2]) {
                return nums[i];
            }
        }
        return nums.back();
    }
};