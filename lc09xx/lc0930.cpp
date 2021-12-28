//--- Q: 0930. Binary Subarrays With Sum

//--- method 1: sliding window one pass
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int left = 0, right = 0, n = nums.size(), res = 0, prefix = 0;
        while (right < n) {
            goal -= nums[right];
            if (goal < 0) {
                prefix = 0;
                while (goal < 0) {
                    goal += nums[left++];
                }
            }
            while (left < right && !nums[left]) {
                ++prefix, ++left;
            }
            if (!goal && left <= right) {
                res += 1+prefix;
            }
            ++right;
        }
        return res;
    }
};