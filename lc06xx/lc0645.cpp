//--- Q: 0645. Set Mismatch

//--- method 1: mark visited value to negative
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(), sum = n*(1+n)/2, csum = 0, dup;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[abs(nums[i])-1] < 0) {
                dup = abs(nums[i]);
            } else {
                nums[abs(nums[i])-1] *= -1;
            }
            csum += abs(nums[i]);
        }
        return {dup, sum-(csum-dup)};
    }
};