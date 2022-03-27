//--- Q: 2110. Number of Smooth Descent Periods of a Stock

//--- method 1: count length
class Solution {
public:
    using ll = long long;
    long long getDescentPeriods(vector<int>& prices) {
        int last = -1, n = prices.size();
        ll res = 0;
        for (int i = 0; i < n; ++i) {
            res = res + (i-last);
            if (i+1 < n && prices[i]-1 != prices[i+1]) {
                last = i;
            }
        }
        return res;
    }
};

//--- method 2: dp O(n) space
class Solution {
public:
    using ll = long long;
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        ll res = 1;
        vector<ll> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (prices[i-1]-1 != prices[i]) {
                dp[i] = 1;
            } else {
                dp[i] = dp[i-1]+1;
            }
            res += dp[i];
        }
        return res;
    }
};

//--- method 3: dp O(1) space
class Solution {
public:
    using ll = long long;
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        ll res = 1, cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (prices[i-1]-1 != prices[i]) {
                cnt = 1;
            } else {
                ++cnt;
            }
            res += cnt;
        }
        return res;
    }
};