//--- Q: 0311. Sparse Matrix Multiplication

//--- method 1: skip 0 computation
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(), n = mat1[0].size(), o = mat2[0].size();
        vector<vector<int>> res(m, vector<int>(o, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!mat1[i][j]) {
                    continue;
                }
                for (int k = 0; k < o; ++k) {
                    res[i][k] += mat1[i][j]*mat2[j][k];
                }
            }
        }
        return res;
    }
};