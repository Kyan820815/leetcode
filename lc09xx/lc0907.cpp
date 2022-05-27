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

//--- method 2: only increasing stack without dp
class Solution {
public:
    using ll = long long;
    int sumSubarrayMins(vector<int>& arr) {
        ll n = arr.size(), mod = 1e9+7, res = 0;
        vector<int> sk = {-1};
        for (int i = 0; i <= n; ++i) {
            int curval = i == n ? INT_MIN : arr[i];
            while (sk.back() != -1 && arr[sk.back()] > curval) {
                int idx = sk.back();
                sk.pop_back();
                res = (res + (idx-sk.back()) * (i-idx) * (ll)arr[idx]) % mod;
            }
            sk.push_back(i);
        }
        return res;
    }
};