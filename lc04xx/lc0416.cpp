//--- Q: 0416. Partition Equal Subset Sum

//--- method 1: coin change adding, O(nm)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto &num: nums) {
            sum += num;
        }
        if (sum % 2 == 1) {
            return false;
        }
        vector<int> dp(sum/2+1, 0);
        dp[0] = 1;
        for (auto &num: nums) {
            auto tmp = dp;
            for (int i = num; i <= sum/2; ++i) {
                tmp[i] |= dp[i-num];
            }
            dp = tmp;
        }
        return dp.back();
    }
};

//--- method 2: bit method, O(n)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto &num: nums) {
            sum += num;
        }
        if (sum % 2 == 1) {
            return false;
        }
        bitset<10001> set(1);
        for (auto &num: nums) {
            set |= (set << num);
        }
        return set[sum/2];
    }
};

//--- method 2: dp, O(nm)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto &num: nums) {
            sum += num;
        }
        if (sum % 2 == 1) {
            return false;
        }
        vector<int> dp(sum/2+1, 0);
        dp[0] = 1;
        for (auto &num: nums) {
            for (int i = sum/2; i >= num; --i) {
                dp[i] |= dp[i-num];
            }
        }
        return dp.back();
    }
};