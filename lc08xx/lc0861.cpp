//--- Q: 0861. Score After Flipping Matrix

//--- method 1: greedy approach
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), res = row*(1 << (col-1));
        for (int j = 1; j < col; ++j) {
            int same = 0;
            for (int i = 0; i < row; ++i) {
                same += grid[i][0] == grid[i][j];
            }
            int maxv = max(same, row-same);
            res += maxv*(1 << (col-j-1));
        }
        return res;
    }
};