//--- Q: 2008. Maximum Earnings From Taxi

//--- method 1: O(n+m)
class Solution {
public:
    using ll = long long;
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<ll> dp(n+1, 0);
        vector<vector<array<int,2>>> cnt(n+1);
        for (auto &ride: rides) {
            cnt[ride[1]].push_back({ride[0], ride[2]});
        }
        ll res = 0;
        for (int i = 1; i <= n; ++i) {
            for (auto &node: cnt[i]) {
                dp[i] = max(dp[i], dp[node[0]]+node[1]+i-node[0]);
            }
            dp[i] = max(dp[i], dp[i-1]);
        }
        return dp[n];
    }
};

//--- method 2: O(klogk + n)
class Solution {
public:
    using ll = long long;
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<ll> dp(n+1, 0);
        sort(rides.begin(), rides.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });
        ll res = 0;
        int j = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i-1];
            while (j < rides.size() && rides[j][1] == i) {
                dp[i] = max(dp[i], dp[rides[j][0]]+i-rides[j][0]+rides[j][2]);
                ++j;
            }
        }
        return dp[n];
    }
};
