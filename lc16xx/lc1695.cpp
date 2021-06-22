//--- Q: 1695. Maximum Erasure Value

//--- method 1: two pointer sliding window
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> cnt(10001, 0);
        int left = 0, right = 0, sum = 0, res = 0;
        while (right < nums.size()) {
            ++cnt[nums[right]];
            sum += nums[right];
            while (cnt[nums[right]] > 1) {
                sum -= nums[left];
                --cnt[nums[left++]];
            }
            ++right;
            res = max(res, sum);
        }
        return res;
    }
};