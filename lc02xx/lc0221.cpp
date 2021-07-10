//--- Q: 0221. Maximal Square

//--- method 1: dp iteration, O(n^2)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size(), res = 0;
        vector<vector<int>> dp(row, vector<int>(col, 1));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                    continue;
                }
                if (i && j) {
                    dp[i][j] += min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
                }
                res = max(res, dp[i][j]);
            }
        }
        return res*res;
    }
};

//--- method 2: dp iteration, O(n)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size(), res = 0;
        vector<int> dp(col, 0);
        for (int i = 0; i < row; ++i) {
            int last = 0, now;
            for (int j = 0; j < col; ++j) {
                now = dp[j];
                if (matrix[i][j] == '0') {
                    dp[j] = 0;
                    continue;
                }
                if (i && j) {
                    dp[j] = min(last, min(dp[j-1], dp[j])) + 1;
                } else {
                    dp[j] = 1;
                }
                res = max(res, dp[j]);
                last = now;
            }
        }
        return res*res;
    }
};