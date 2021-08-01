//--- Q: 0566. Reshape the Matrix

//--- method 1: O(n*m)
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> res(r, vector<int>(c, 0));
        int row = mat.size(), col = mat[0].size(), ri = 0, cj = 0;
        if (row*col != r*c) {
            return mat;
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                res[ri][cj++] = mat[i][j];
                if (cj == c) {
                    ++ri, cj = 0;
                }
            }
        }
        return res;
    }
};