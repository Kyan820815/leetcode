//--- Q: 2134. Minimum Swaps to Group All 1's Together II

//--- method 1: prefix sum and sliding window
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), ones, res = INT_MAX;
        for (int i = 1; i < n; ++i) {
            nums[i] += nums[i-1];
        }
        ones = nums.back();
        for (int end = 0; end < n; ++end) {
            int start = (end-ones+n)%n;
            if (start < end) {
                res = min(res, ones-(nums[end]-nums[start]));
            } else {
                res = min(res, ones-(nums[end]+(nums.back()-nums[start])));
            }
        }
        return res;
    }
};