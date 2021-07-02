//--- Q: 0073. Set Matrix Zeroes

//--- method 1: matrix operation
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size(), isCol = 0, isRow = 0;
        for (int i = 0; i < row; ++i) {
            if (!matrix[i][0]) {
                isCol = 1;
                break;
            }
        }
        for (int j = 0; j < col; ++j) {
            if (!matrix[0][j]) {
                isRow = 1;
                break;
            }
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (!matrix[i][j]) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (isCol) {
            for (int i = 0; i < row; ++i) {
                matrix[i][0] = 0;
            }
        }
        if (isRow) {
            for (int j = 0; j < col; ++j) {
                matrix[0][j] = 0;
            }
        }
    }
};