//--- Q: 0907. Sum of Subarray Minimums

//--- method 1: using increasing monotone stack
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), mod = 1e9+7, res = 0;
        vector<int> sk = {-1}, dp(n, 0);
        for (int i = 0; i < n; ++i) {
            while (sk.back() != -1 && arr[sk.back()] > arr[i]) {
                sk.pop_back();
            }
            dp[i] = (i-sk.back())*arr[i] + (sk.back() == -1 ? 0 : dp[sk.back()]);
            sk.push_back(i);
            res = (res+dp[i])%mod;
        }
        return res;
    }
};
