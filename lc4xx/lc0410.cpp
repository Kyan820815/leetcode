//--- Q: 410. Split Array Largest Sum

//--- method 1: binary search
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = 0;
        long right = 0;
        for (int i = 0; i < nums.size(); ++i) {
            right += nums[i];
            left = max(left, nums[i]);
        }
        while (left < right) {
            long mid = (right-left)/2 + left;
            if (cansplit(mid, nums, m)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return right;
    }
    bool cansplit(long &mid, vector<int> &nums, int m) {
        int cnt = 1;
        long cursum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            cursum += nums[i];
            if (cursum > mid) {
                cursum = nums[i];
                ++cnt;
                if (cnt > m) {
                    return false;
                }
            }
        }
        return true;
    }
};

//--- method 2: linear search
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<vector<long>> dp(m, vector<long>(nums.size()+1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            dp[0][i] = dp[0][i-1] + nums[i-1];
        }
        return dfs(dp, m-1, 1, nums.size());
    }
    long dfs(vector<vector<long>> &dp, int k, int start, int end) {
        if (!k || k > end-start) {
            return dp[k][end] = dp[0][end] - dp[0][start-1];
        }
        if (dp[k][end] != INT_MAX) {
            return dp[k][end];
        }
        for (int j = start; j < end; ++j) {
            long val = max(dfs(dp, k-1, start, j), dp[0][end] - dp[0][j]);
            dp[k][end] = min(dp[k][end], val);
        }
        return dp[k][end];
    }
};

