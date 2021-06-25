//--- Q: 304. Range Sum Query 2D - Immutable

//--- method 1: prefix sum
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (!matrix.size()) {
            return;
        }
        int row = matrix.size(), col = matrix[0].size();
        for (int i = 1; i < row; ++i) {
            matrix[i][0] += matrix[i-1][0];
        }
        for (int j = 1; j < col; ++j) {
            matrix[0][j] += matrix[0][j-1];
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                matrix[i][j] += matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
            }
        }
        sum = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int left = col1-1 >= 0 ? sum[row2][col1-1] : 0;
        int top = row1-1 >= 0 ? sum[row1-1][col2] : 0;
        int dig = col1-1 >= 0 && row1-1 >= 0 ? sum[row1-1][col1-1] : 0;
        return sum[row2][col2] - left - top + dig;
    }
    vector<vector<int>> sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */