//--- Q: 1937. Maximum Number of Points with Cost

//--- method 1: O(mn) space
class Solution {
public:
    using ll = long long;
    long long maxPoints(vector<vector<int>>& points) {
        int row = points.size(), col = points[0].size();
        vector<vector<ll>> dp(row, vector<ll>(col, 0));
        for (int j = 0; j < col; ++j) {
            dp[0][j] = points[0][j];
        }
        for (int i = 1; i < row; ++i) {
            ll best = 0;
            for (int j = col-1; j >= 0; --j) {
                best = max(best-1, dp[i-1][j]);
                dp[i][j] = points[i][j] + best;
            }
            best = 0;
            for (int j = 0; j < col; ++j) {
                best = max(best-1, dp[i-1][j]);
                dp[i][j] = max(dp[i][j], points[i][j] + best);
            }
        }
        ll res = 0;
        for (int j = 0; j < col; ++j) {
            res = max(res, dp[row-1][j]);
        }
        return res;
    }
};

//--- method 2: O(n) space
class Solution {
public:
    using ll = long long;
    long long maxPoints(vector<vector<int>>& points) {
        int row = points.size(), col = points[0].size();
        vector<ll> dp(col, 0);
        for (int j = 0; j < col; ++j) {
            dp[j] = points[0][j];
        }
        for (int i = 1; i < row; ++i) {
            ll best = 0;
            vector<ll> next(col, 0);
            for (int j = col-1; j >= 0; --j) {
                best = max(best-1, dp[j]);
                next[j] = points[i][j] + best;
            }
            best = 0;
            for (int j = 0; j < col; ++j) {
                best = max(best-1, dp[j]);
                next[j] = max(next[j], points[i][j] + best);
            }
            dp = next;
        }
        ll res = 0;
        for (int j = 0; j < col; ++j) {
            res = max(res, dp[j]);
        }
        return res;
    }
};