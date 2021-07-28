//--- Q: 0494. Target Sum

//--- method 1: recursion dp
class Solution {
public:
    vector<unordered_map<int, int>> map;
    int findTargetSumWays(vector<int>& nums, int target) {
        map.resize(nums.size()+1);
        return dfs(nums.size(), target, nums);
    }
    int dfs(int idx, int target, vector<int> &nums) {
        if (!idx) {
            if (!target) {
                return map[idx][target] = 1;
            } else {
                return map[idx][target] = 0;
            }
        }
        if (map[idx].find(target) != map[idx].end()) {
            return map[idx][target];
        }
        int sum = dfs(idx-1, target+nums[idx-1], nums) + dfs(idx-1, target-nums[idx-1], nums);
        return map[idx][target] = sum;
    }
};

//--- method 2: iteration dp, space: O(n)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> dp;
        dp[0] = 1;
        for (auto &num: nums) {
            unordered_map<int, int> tmp;
            for (auto &node: dp) {
                tmp[node.first+num] += node.second;
                tmp[node.first-num] += node.second;
            }
            dp = tmp;
        }
        return dp[target];
    }
};

//--- method 3: partitial sum
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = target;
        for (auto &num: nums) {
            sum += num;
        }
        if (sum%2 == 1) {
            return 0;
        }
        vector<int> dp(sum/2+1, 0);
        dp[0] = 1;
        for (auto &num: nums) {
            for (int i = sum/2; i >= num; --i) {
                dp[i] += dp[i-num];
            }
        }
        return dp.back();
    }
};