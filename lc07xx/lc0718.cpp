//--- Q: 0718. Maximum Length of Repeated Subarray

//--- method 1: dp iteration, better
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), res = 0;
        vector<int> dp(m+1, 0);
        for (int i = 1; i <= n; ++i) {
            int pre = 0, now;
            for (int j = 1; j <= m; ++j) {
                now = dp[j];
                if (nums1[i-1] == nums2[j-1]) {
                    dp[j] = pre+1;
                } else {
                    dp[j] = 0;
                }
                pre = now;
                res = max(res, dp[j]);
            }
        }
        return res;
    }
};