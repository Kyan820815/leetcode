//--- Q: 311. Sparse Matrix Multiplication

//--- method 1: skip 0 computation
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int res_row = A.size(), res_col = B[0].size();
        int midlen = A[0].size();
        vector<vector<int>> res(res_row, vector<int>(res_col, 0));
        
        for (int i = 0; i < res_row; ++i) {
            for (int k = 0; k < midlen; ++k) {
                if (A[i][k]) {
                    for (int j = 0; j < res_col; ++j) {
                        if (B[k][j])
                            res[i][j] += A[i][k]*B[k][j];
                    }
                }
            }
        }
        return res;
    }
};