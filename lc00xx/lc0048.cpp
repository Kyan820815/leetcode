//--- Q: 0048. Rotate Image
//--- last written: 2023/06/09

//--- method 1: vertical rotation then diagonal rotatiion
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        for (int i = 0; i < row/2; ++i) {
            for (int j = 0; j < col; ++j) {
                swap(matrix[i][j], matrix[row-i-1][j]);
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
