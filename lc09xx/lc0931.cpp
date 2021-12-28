//--- Q: 0931. Minimum Falling Path Sum

//--- method 1: dp, space O(1)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size(), res = INT_MAX;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (i) {
                    int minv = matrix[i-1][j];
                    if (j) {
                        minv = min(minv, matrix[i-1][j-1]);
                    }
                    if (j+1 < col) {
                        minv = min(minv, matrix[i-1][j+1]);
                    }
                    matrix[i][j] += minv;
                }
                if (i == row-1) {
                    res = min(res, matrix[i][j]);
                }
            }
        }
        return res;
    }
};