//--- Q: 2017. Grid Game

//--- method 1: prefix sum
class Solution {
public:
    using ll = long long;
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        ll lsum = 0, rsum = accumulate(grid[0].begin(), grid[0].end(), (ll)0);
        ll res = LONG_MAX;
        for (int i = 0; i < n; ++i) {
            rsum -= grid[0][i];
            res = min(res, max(lsum, rsum));
            lsum += grid[1][i];
        }
        return res;
    }
};