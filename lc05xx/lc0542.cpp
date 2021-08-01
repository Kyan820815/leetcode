//--- Q: 0542. 01 Matrix

//--- method 1: double pass
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        vector<vector<int>> res(row, vector<int>(col, INT_MAX-1));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (!mat[i][j]) {
                    res[i][j] = 0;
                } else {
                    if (i) {
                        res[i][j] = min(res[i][j], res[i-1][j]+1);
                    }
                    if (j) {
                        res[i][j] = min(res[i][j], res[i][j-1]+1);
                    }
                }
            }
        }
        for (int i = row-1; i >= 0; --i) {
            for (int j = col-1; j >= 0; --j) {
                if (!mat[i][j]) {
                    continue;
                }
                if (i+1 < row) {
                    res[i][j] = min(res[i][j], res[i+1][j]+1);
                }
                if (j+1 < col) {
                    res[i][j] = min(res[i][j], res[i][j+1]+1);
                }
            }
        }
        return res;
    }
};