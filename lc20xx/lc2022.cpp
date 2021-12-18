//--- Q: 2022. Convert 1D Array Into 2D Array

//--- method 1: linear processing
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m*n) {
            return {};
        }
        vector<vector<int>> res(m, vector<int>(n, 0));
        int idx = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i][j] = original[idx++];
            }
        }
        return res;
    }
};