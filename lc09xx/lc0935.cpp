//--- Q: 0935. Knight Dialer

//--- method 1: bfs
class Solution {
public:
    int knightDialer(int n) {
        vector<int> dp(10, 1);
        vector<vector<int>> dir = {{4,6}, {6,8}, {7,9}, {4,8}, {0,3,9}, {}, {0,1,7}, {2,6}, {1,3}, {2,4}};
        int mod = 1e9+7, res = 0;
        for (int i = 2; i <= n; ++i) {
            vector<int> tmp(10, 0);
            for (int j = 0; j < 10; ++j) {
                for (auto &last: dir[j]) {
                    tmp[j] = (tmp[j] + dp[last])%mod;
                }
            }
            dp = tmp;
        }
        for (auto &val: dp) {
            res = (res + val)%mod;
        }
        return res;
    }
};