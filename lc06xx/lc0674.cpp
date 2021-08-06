//--- Q: 0674. Longest Continuous Increasing Subsequence

//--- method 1: linear processing
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cnt = 1, res = 1;
        for (int i = 1; i <= nums.size(); ++i) {
            if (i == nums.size() || nums[i-1] >= nums[i]) {
                res = max(res, cnt);
                cnt = 0;
            }
            ++cnt;
        }
        return res;
    }
};