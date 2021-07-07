//--- Q: 0198. House Robber

//--- method 1: dp, O(n), space O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            if (i) {
                dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
            }
        }
        return max(dp[n-1], dp[n-2]);
    }
};

//--- method 2: dp, O(n), space O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int odd = 0, even = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i&1) {
                odd = max(even, odd+nums[i]);
            } else {
                even = max(odd, even+nums[i]);
            }
        }
        return max(odd, even);
    }
};