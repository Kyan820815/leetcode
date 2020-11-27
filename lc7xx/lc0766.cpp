//--- Q: 766. Toeplitz Matrix

//--- method 1: clean code, better
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        for (int i = 0; i < row-1; ++i) {
            for (int j = 0; j < col-1; ++j) {
                if (matrix[i][j] != matrix[i+1][j+1]) {
                    return false;
                }
            }
        }        
        return true;
    }
};

//--- method 2:
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int r = row-1;
        for (int sr = row-1; sr >= 0; --sr) {
            int r = sr, c = 0, val = matrix[r][c];
            while (r < row && c < col) {
                if (matrix[r][c] != val) {
                    return false;
                }
                ++r, ++c;
            }
        }
        for (int sc = 1; sc < col; ++sc) {
            int r = 0, c = sc, val = matrix[r][c];
            while (r < row && c < col) {
                if (matrix[r][c] != val) {
                    return false;
                }
                ++r, ++c;
            }
        }
        return true;
    }
};