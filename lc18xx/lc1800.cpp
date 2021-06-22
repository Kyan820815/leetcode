//--- Q: 1800. Maximum Ascending Subarray Sum

//--- method 1: two pointer
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int idx = 0, res = 0, sum = 0;
        while (idx < nums.size()) {
            if (idx && nums[idx] <= nums[idx-1]) {
                sum = 0;
            }
            sum += nums[idx++];
            res = max(res, sum);
        }
        return res;
    }
};