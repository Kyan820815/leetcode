//--- Q: 0698. Partition to K Equal Sum Subsets

//--- method 1: top down bit manipulation
class Solution {
public:
    vector<int> dp;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        for (auto &num: nums) {
            sum += num;
        }
        sort(nums.rbegin(), nums.rend());
        dp.resize(1<<n, -1);
        return sum%k == 0 && dfs(0, 0, k, sum/k, nums, 0);
    }
    int dfs(int idx, int cur, int k, int part, vector<int> &nums, int state) {
        if (dp[state] != -1) {
            return dp[state];
        }
        if (!k) {
            return dp[state] = 1;
        }
        for (int i = idx; i < nums.size(); ++i) {
            if (!(state&(1<<i)) && cur+nums[i] <= part) {
                if (cur + nums[i] == part) {
                    if (dfs(0, 0, k-1, part, nums, state|(1<<i))) {
                        return dp[state] = 1;
                    }
                } else {
                    if (dfs(i+1, cur+nums[i], k, part, nums, state|(1<<i))) {
                        return dp[state] = 1;
                    }
                }
            }
        }
        return dp[state] = 0;
    }
};

//--- method 2: bottom up bit manipulation
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        vector<int> dp(1<<n, -1);
        for (auto &num: nums) {
            sum += num;
        }
        if (sum%k != 0) {
            return false;
        }
        int part = sum/k;
        vector<int> bucket(1<<n, -1);
        bucket[0] = 0;
        for (int state = 0; state < (1<<n); ++state) {
            if (bucket[state] == -1) {
                continue;
            }
            for (int i = 0; i < n; ++i) {
                if (state&(1<<i) || bucket[state]+nums[i] > part) {
                    continue;
                }
                bucket[state|(1<<i)] = (bucket[state]+nums[i])%part;
            }
        }
        return bucket[(1<<n)-1] == 0;
    }
};

//--- method 3: bucket fill
class Solution {
public:
    vector<int> used;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        used.resize(n, 0);
        for (auto &num: nums) {
            sum += num;
        }
        sort(nums.rbegin(), nums.rend());
        used[0] = 1;
        return sum%k == 0 && dfs(1, nums[0], k, sum/k, nums);
    }
    bool dfs(int idx, int cur, int k, int part, vector<int> &nums) {
        if (cur == part) {
            if (k == 1) {
                return true;
            }
            return dfs(0, 0, k-1, part, nums);
        }
        for (int i = idx; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }
            used[i] = 1;
            if (cur+nums[i] <= part && dfs(i+1, cur+nums[i], k, part, nums)) {
                used[i] = 0;
                return true;
            }
            used[i] = 0;
        }
        return false;
    }
};