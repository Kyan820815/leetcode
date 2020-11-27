//--- Q: 1260. Shift 2D Grid

//--- method 1: O(m*n)
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size(), col = grid[0].size();
        int shift = k % col, times = k / col;
        vector<vector<int>> res(row, vector<int>(col, 0));
        for (int i = col-1, s = shift; i >= 0; --i, --s) {
            for (int j = 0; j < row; ++j) {
                int shift_r = (j + times + (s > 0)) % row;
                res[shift_r][(i+shift) % col] = grid[j][i];
            }
        }
        return res;
    }
};