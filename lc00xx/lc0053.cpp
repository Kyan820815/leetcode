//--- Q: 0053. Maximum Subarray
//--- last written: 2023/06/16

//--- method 1: dp with space O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int res;
        res = dp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = nums[i] + max(dp[i-1],0);
            res = max(res, dp[i]);
        }
        return res;
    }
};

//--- method 2: dp with space O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], maxv = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            maxv = nums[i] + max(maxv,0);
            res = max(res, maxv);
        }
        return res;
    }
};
