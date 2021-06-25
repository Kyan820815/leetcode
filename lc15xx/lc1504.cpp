//--- Q: 1504. Count Submatrices With All Ones

//--- method 1: find rectangle from now to top
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size(), res = 0;
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (!mat[i][j]) {
                    continue;
                }
                dp[i][j] = 1;
                if (j) {
                    dp[i][j] += dp[i][j-1];
                }
                int side = INT_MAX;
                for (int k = i; k >= 0 && dp[k][j]; --k) {
                    side = min(side, dp[k][j]);
                    res += side;
                }
            }
        }
        return res;
    }
};

//--- method 2: increasing histogram stack
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size(), res = 0;
        vector<int> dp(col+1, 0);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                dp[j] = !mat[i][j] ? 0 : dp[j]+1;
            }
            vector<int> sk = {-1}, sum(col+1, 0);
            for (int j = 0; j <= col; ++j) {
                while (sk.back() != -1 && dp[sk.back()] >= dp[j]) {
                    sk.pop_back();                    
                }
                sum[j] = (j-sk.back())*dp[j] + (sk.back() == -1 ? 0 : sum[sk.back()]);
                sk.push_back(j);
            }
            for (auto &v: sum) {
                res += v;
            }
        }
        return res;
    }
};