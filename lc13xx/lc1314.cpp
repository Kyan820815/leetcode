//--- Q: 1314. Matrix Block Sum

//--- method 1: prefix sum
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int row = mat.size(), col = mat[0].size();;
        vector<vector<int>> dp(row, vector<int>(col, 0));
        vector<vector<int>> sum(row, vector<int>(col, 0));
        dp[0][0] = mat[0][0];
        for (int i = 1; i < row; ++i) {
            dp[i][0] = dp[i-1][0] + mat[i][0];
        }
        for (int j = 1; j < col; ++j) {
            dp[0][j] = dp[0][j-1] + mat[0][j];
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mat[i][j];
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int upr = (i+K >= row) ? row-1 : i+K;
                int upc = (j+K >= col) ? col-1 : j+K;
                int leftsum = 0, topsum = 0, prevsum = 0;
                if (i-K-1 >= 0 && j-K-1 >= 0) {
                    prevsum = dp[i-K-1][j-K-1];
                    leftsum = dp[upr][j-K-1];
                    topsum = dp[i-K-1][upc];
                } else if (j-K-1 >= 0) {
                    leftsum = dp[upr][j-K-1];
                } else if (i-K-1 >= 0) {
                    topsum = dp[i-K-1][upc];
                }
                sum[i][j] = dp[upr][upc] - leftsum - topsum + prevsum;
                // sum[i][j] = dp[i+k][j+k] - dp[i+k][j-k-1] - dp[i-k-1][j+k] + dp[i-k-1][j-k-1];
            }
        }
        return sum;
    }
};