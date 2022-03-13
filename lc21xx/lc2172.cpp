//--- Q: 2172. Maximum AND Sum of Array

//--- method 1: base 3 mask
class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int mask = pow(3, numSlots)-1;
        vector<int> dp(mask+1, 0);
        return dfs(nums.size()-1, mask, numSlots, nums, dp);
    }
    int dfs(int i, int mask, int ns, vector<int> &nums, vector<int> &dp) {
        if (dp[mask] > 0) {
            return dp[mask];
        }
        if (i < 0) {
            return 0;
        }
        for (int bit = 1, j = 1; j <= ns; bit*=3, ++j) {
            if ((mask/bit) % 3 > 0) {
                dp[mask] = max(dp[mask], (nums[i]&j) + dfs(i-1, mask-bit, ns, nums, dp));
            }
        }
        return dp[mask];
    }
};

//--- method 2: base 2 mask
class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int mask = pow(2, numSlots*2)-1;
        vector<int> dp(mask+1, 0);
        return dfs(nums.size()-1, mask, numSlots, nums, dp);
    }
    int dfs(int i, int mask, int ns, vector<int> &nums, vector<int> &dp) {
        if (dp[mask] > 0) {
            return dp[mask];
        }
        if (i < 0) {
            return 0;
        }
        for (int bit = 1, j = 1; j <= ns; bit*=4, ++j) {
            if ((mask/bit) % 4 == 3) {
                dp[mask] = max(dp[mask], (nums[i]&j) + dfs(i-1, mask-bit, ns, nums, dp));
            } else if ((mask/bit) % 4 == 2) {
                dp[mask] = max(dp[mask], (nums[i]&j) + dfs(i-1, mask-bit*2, ns, nums, dp));
            }
        }
        return dp[mask];
    }
};