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
        vector<vector<int>> dp(m, vector<int>(nums.size()+1, -1));
        dp[0][0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            dp[0][i+1] = dp[0][i] + nums[i];
        }
        return dfs(nums.size(), m-1, dp);
    }
    int dfs(int end, int m, vector<vector<int>> &dp) {
        if (!m || end-1 < m) {
            return dp[m][end] = dp[0][end];
        }
        if (dp[m][end] != -1) {
            return dp[m][end];
        }
        int minv = INT_MAX;
        for (int i = 1; i <= end; ++i) {
            int leftv = dfs(i, m-1, dp);
            int rightv = dp[0][end] - dp[0][i];
            minv = min(minv, max(leftv, rightv));
        }
        return dp[m][end] = minv;
    }
};

