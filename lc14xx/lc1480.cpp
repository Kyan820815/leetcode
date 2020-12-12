//--- Q: 1480. Running Sum of 1d Array

//--- method 1: add the last value
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i-1];
        }
        return nums;
    }
};