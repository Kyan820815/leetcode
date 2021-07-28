//--- Q: 0410. Split Array Largest Sum

//--- method 1: linear search
class Solution {
public:
    vector<vector<int>> dp;
    int splitArray(vector<int>& nums, int m) {
        dp.resize(m, vector<int>(nums.size(), -1));
        dp[0][0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[0][i] = dp[0][i-1] + nums[i];
        }
        return dfs(m-1, nums.size()-1);
    }
    int dfs(int m, int idx) {
        if (dp[m][idx] != -1) {
            return dp[m][idx];
        }
        if (m > idx) {
            return dp[m][idx] = INT_MAX;
        }
        int minv = INT_MAX;
        for (int i = 0; i < idx; ++i) {
            int left = dfs(m-1, i);
            int right = dp[0][idx]-dp[0][i];
            minv = min(minv, max(left, right));
        }
        return dp[m][idx] = minv;
    }
};

//--- method 2: binary search
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = 0, right = 0;
        for (auto &num: nums) {
            left = max(left, num);
            right += num;
        }
        while (left < right) {
            int mid = left + (right-left)/2;
            if (cansplit(mid, m-1, nums)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
    bool cansplit(int limit, int m, vector<int> &nums) {
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum > limit) {
                sum = nums[i];
                if (--m < 0) {
                    return false;
                }
            }
        }
        return true;
    }
};