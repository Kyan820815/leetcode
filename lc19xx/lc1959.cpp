//--- Q: 1959. Minimum Total Space Wasted With K Resizing Operations

//--- method 1: dp
class Solution {
public:
    vector<vector<int>> dp;
    int limit = 200*1e6;
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int n = nums.size();
        dp.resize(n, vector<int>(k+1, -1));
        return dfs(n-1, nums, k);
    }
    int dfs(int idx, vector<int> &nums, int k) {
        if (idx == -1) {
            return 0;
        }
        if (k == -1) {
            return limit;
        }
        if (dp[idx][k] != -1) {
            return dp[idx][k];
        }
        int maxv = 0, waste = INT_MAX, h = 0;
        for (int i = idx; i >= 0; --i) {
            maxv = max(nums[i], maxv);
            h += nums[i];
            waste = min(waste, maxv*(idx-i+1)-h+dfs(i-1, nums, k-1));
        }
        return dp[idx][k] = waste;
    }
};
