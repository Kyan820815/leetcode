//--- Q: 0368. Largest Divisible Subset

//--- method 1: dp, space: O(n) 
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1), idx(nums.size()), res;
        int start = 0, gval = 0;
        for (int i = 0; i < nums.size(); ++i) {
            idx[i] = i;
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < dp[j]+1) {
                        dp[i] = dp[j]+1;
                        idx[i] = j;
                    }
                }
            }
            if (gval < dp[i]) {
                gval = dp[i];
                start = i;
            }
        }
        res.push_back(nums[start]);
        while (start != idx[start]) {
            start = idx[start];
            res.push_back(nums[start]);
        }
        return res;
    }
};
