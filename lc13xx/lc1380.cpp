//--- Q: 1380. Lucky Numbers in a Matrix

//--- method 1: O(1) space
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int min_row = 0, max_col, minv = INT_MAX;
        for (int j = 0; j < col; ++j) {
            if (minv > matrix[0][j]) {
                minv = matrix[0][j];
                max_col = j;
            }
        }
        for (int i = 1; i < row; ++i) {
            minv = INT_MAX;
            int tmp_col;
            for (int j = 0; j < col; ++j) {
                if (minv > matrix[i][j]) {
                    minv = matrix[i][j];
                    tmp_col = j;
                }
            }
            if (matrix[i][tmp_col] > matrix[min_row][max_col]) {
                min_row = i;
                max_col = tmp_col;
            }
        }
        for (int i = 0; i < row; ++i) {
            if (matrix[i][max_col] > matrix[min_row][max_col]) {
                return {};
            }
        }
        return {matrix[min_row][max_col]};
    }
};

//--- method 2: O(n) space
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<int> rowv(row, INT_MAX), colv(col, INT_MIN), res;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                rowv[i] = min(rowv[i], matrix[i][j]);
                colv[j] = max(colv[j], matrix[i][j]);
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == rowv[i] && matrix[i][j] == colv[j]) {
                    res.push_back(matrix[i][j]);
                }
            }
        }
        return res;
    }
};