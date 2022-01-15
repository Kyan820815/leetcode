//--- Q: 1043. Partition Array for Maximum Sum

//--- metho 1: O(n*K)
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size(), maxv = 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < k; ++i) {
            maxv = max(maxv, arr[i]);
            dp[i] = maxv*(i+1);
        }
        for (int i = k; i < n; ++i) {
            int maxv = 0;
            for (int j = i; j > i-k; --j) {
                maxv = max(maxv, arr[j]);
                dp[i] = max(dp[i], dp[j-1]+maxv*(i-j+1));
            }
        }
        return dp.back();
    }
};