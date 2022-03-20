//--- Q: 1182. Shortest Distance to Target Color

//--- method 1: linear search
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<vector<int>> dp(3, vector<int>(n, INT_MAX));
        vector<vector<int>> cnt(3, vector<int>(2, n));
        for (int i = 0, j = n-1; i < n; ++i,--j) {
            for (int k = 0; k < 3; ++k) {
                cnt[k][0] = colors[i] == k+1 ? 0 : cnt[k][0]+1;
                cnt[k][1] = colors[j] == k+1 ? 0 : cnt[k][1]+1;
                dp[k][i] = min(dp[k][i], cnt[k][0]);
                dp[k][j] = min(dp[k][j], cnt[k][1]);
            }
        }
        vector<int> res;
        for (auto &query: queries) {
            int idx = query[0], color = query[1];
            int dis = dp[color-1][idx] >= n ? -1 : dp[color-1][idx];
            res.push_back(dis);
        }
        return res;
    }
};

//--- method 2: binary search
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<set<int>> map(3);
        for (int i = 0; i < n; ++i) {
            map[colors[i]-1].insert(i);
        }
        vector<int> res;
        for (auto &query: queries) {
            int idx = query[0], color = query[1]-1;
            auto it = map[color].lower_bound(idx);
            int left = it == map[color].begin() ? INT_MAX : idx - *prev(it);
            int right = it == map[color].end() ? INT_MAX : *it - idx;
            int dis = min(left, right) == INT_MAX ?-1 : min(left, right);
            res.push_back(dis);
        }
        return res;
    }
};