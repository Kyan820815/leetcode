//--- Q: 1277. Count Square Submatrices with All Ones

//--- method 1: O(n^2)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size(), res = 0;
        vector<vector<int>> presum(row, vector<int>(col, 0));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j]) {
                    if (!i && !j || !i || !j) {
                        presum[i][j] = 1;
                    } else {
                        presum[i][j] = min(presum[i-1][j-1], min(presum[i-1][j], presum[i][j-1])) + 1;
                    }
                    res += presum[i][j];
                }
            }
        }
        return res;
    }
};

//--- method 2: prefix sum, O(n^3)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size(), res = 0;
        vector<vector<int>> presum(row, vector<int>(col, 0));
        presum[0][0] = matrix[0][0];
        for (int i = 1; i < row; ++i) {
            presum[i][0] = presum[i-1][0] + matrix[i][0];
        }
        for (int j = 1; j < col; ++j) {
            presum[0][j] = presum[0][j-1] + matrix[0][j];
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                presum[i][j] = presum[i-1][j] + presum[i][j-1] - presum[i-1][j-1] + matrix[i][j];
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j]) {
                    for (int k = 0; i-k >= 0 && j-k >= 0; ++k) {
                        int topsum = 0, leftsum = 0, lastsum = 0;
                        if (i-k-1 >= 0 && j-k-1 >= 0) {
                            lastsum = presum[i-k-1][j-k-1];
                            leftsum = presum[i][j-k-1];
                            topsum = presum[i-k-1][j];
                        } else if (i-k-1 >= 0) {
                            topsum = presum[i-k-1][j];
                        } else if (j-k-1 >= 0) {
                            leftsum = presum[i][j-k-1];
                        }
                        int now = presum[i][j] - leftsum - topsum + lastsum;
                        if (now == (k+1) * (k+1)) {
                            ++res;
                        }
                        // int now = dp[i][j] - dp[i-k-1][j] - dp[i][j-k-1] + dp[i-k-1][j-k-1];
                    }
                }
            }
        }
        return res;
    }
}; 