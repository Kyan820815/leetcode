//--- Q: 0918. Maximum Sum Circular Subarray

//--- method 1: find maxsum and minsum
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(), maxsum = 0, minsum = 0, totalsum = 0, resmax = INT_MIN, resmin = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (maxsum < 0) {
                maxsum = 0;
            }
            if (minsum > 0) {
                minsum = 0;
            }
            maxsum += nums[i];
            minsum += nums[i];
            totalsum += nums[i];
            resmin = min(resmin, minsum);
            resmax = max(resmax, maxsum);
        }
        int corcularmax = totalsum == resmin ? INT_MIN : totalsum-resmin;
        return max(resmax, corcularmax);
    }
};