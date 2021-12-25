//--- Q: 0823. Binary Trees With Factors

//--- method 1: dp iteration
class Solution {
public:
    using ll = long long;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), res = 0, mod = 1e9+7;
        unordered_map<int,ll> dp;
        for (int i = 0; i < n; ++i) {
            dp[arr[i]] = 1;
            for (int j = 0; j < i; ++j) {
                if (arr[i]%arr[j] == 0 && dp.find(arr[i]/arr[j]) != dp.end()) {
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]]*dp[arr[i]/arr[j]]) % mod;
                }
            }
            res = (res+dp[arr[i]]) % mod;
        }
        return res;
    }
};