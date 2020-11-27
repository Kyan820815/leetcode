//--- Q: Jump Game II

//--- method 1: O(n) space, O(n) time
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int maxv = 0;
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i+nums[i] >= nums.size()-1)
                return dp[i]+1;
            else if (i+nums[i] <= maxv)
                continue;
            for (int j = maxv+1; j <= i+nums[i]; ++j)
                dp[j] = dp[i]+1;
            maxv = i+nums[i];
        }
        return dp[nums.size()-1];
    }
};

//--- method 2: O(1) space, O(n) time
class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, cur = 0, last = 0;
        for (int i = 0; i < nums.size()-1; ++i) {
            cur = max(cur, i+nums[i]);
            if (i == last) {
                ++res;
                last = cur;
                if (cur >= nums.size()-1)
                    return res;
            }
            if (i > last)
                return -1;
        }
        return res;
    }
};
