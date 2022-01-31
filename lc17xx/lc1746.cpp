//--- Q: 1786. Maximum Subarray Sum After One Operation

//--- method 1: dp iteration
class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int perform = nums[0]*nums[0], notperform = nums[0], res = perform;
        for (int i = 1; i < nums.size(); ++i) {
            notperform = max(0, notperform);
            perform = max(perform+nums[i], notperform+nums[i]*nums[i]);
            notperform += nums[i];
            res = max(res, perform);
        }
        return res;
    }
};