//--- Q: 0377. Combination Sum IV

//--- method 1: bottom up iteration
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (auto &num: nums) {
                if (i-num >= 0 && (long long)dp[i]+dp[i-num] < INT_MAX) {
                    dp[i] += dp[i-num];
                }
            }
        }
        return dp[target];
    }
};

//--- method 2: top down recursion
class Solution {
public:
    vector<int> dp;
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target+1, -1);
        dp[0] = 1;
        return dfs(nums, target);
    }
    int dfs(vector<int> &nums, int target) {
        if (dp[target] != -1) {
            return dp[target];
        }
        int res = 0;
        for (auto &num: nums) {
            if (target-num >= 0) {
                res += dfs(nums, target-num);
            }
        }
        return dp[target] = res;
    }
};

//--- follow up: negative elements
class Solution {
public:
    unordered_map<int, unordered_map<int, int>> map;
    int combinationSum4(vector<int>& nums, int target, int length) {
        return dfs(target, length, nums);
    }
    int dfs(int target, int length, vector<int> &nums) {
        if (length < 0) {
            return 0;
        }
        if (map.find(target) != map.end() && map[target].find(length) != map[target].end()) {
            return map[target][length];
        }
        int cnt = 0;
        if (!target && length >= 0) {
            ++cnt;
        }
        for (auto &num: nums) {
            cnt += dfs(target-num, length-1, nums);
        }
        return map[target][length] = cnt;
    }
};