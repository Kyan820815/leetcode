//--- Q: 416. Partition Equal Subset Sum

//--- method 1: bit method, O(n)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<10001> sum_bit(1);
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
            sum += nums[i];
        if (sum % 2 == 1) return 0;
        for (int i = 0; i < nums.size(); ++i)
            sum_bit = (sum_bit<<nums[i]) | sum_bit;
        return sum_bit[sum/2];
    }
};

//--- method 2: dp, O(n^2)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)      
            sum += nums[i];
        if (sum%2 == 1) return false;
        vector<bool> dp(sum/2+1,false);

        dp[0] = true;
        for (int i = 0; i < nums.size(); ++i)
            for (int j = sum/2; j >= nums[i]; --j)
                if (dp[j-nums[i]])
                    dp[j] = true;
        return dp[sum/2];
    }
};