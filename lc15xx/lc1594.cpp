//--- Q: 1594. Maximum Non Negative Product in a Matrix

//--- method 1: dp
class Solution {
public:
    using ll = long long;
    int maxProductPath(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), mod=1e9+7;
        vector<vector<pair<ll,ll>>> val(row, vector<pair<ll,ll>>(col));
        val[0][0].first = val[0][0].second = grid[0][0];
        for (int i = 1; i < row; ++i) {
            val[i][0].first = val[i][0].second = val[i-1][0].first*grid[i][0];
        }
        for (int j = 1; j < col; ++j) {
            val[0][j].first = val[0][j].second = val[0][j-1].first*grid[0][j];
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (grid[i][j] > 0) {
                    val[i][j].first = min(val[i-1][j].first, val[i][j-1].first) * grid[i][j];
                    val[i][j].second = max(val[i-1][j].second, val[i][j-1].second) * grid[i][j];
                } else {
                    val[i][j].first = max(val[i-1][j].second, val[i][j-1].second) * grid[i][j];
                    val[i][j].second = min(val[i-1][j].first, val[i][j-1].first) * grid[i][j];
                }
            }
        }
        return val[row-1][col-1].second >= 0 ? val[row-1][col-1].second%mod : -1;
    }
};