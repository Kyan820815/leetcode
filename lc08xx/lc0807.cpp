//--- Q: 807. Max Increase to Keep City Skyline

//--- method 1: find max of row & col than compute diff
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<int> rowmax(row, INT_MIN);
        vector<int> colmax(col, INT_MIN);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                rowmax[i] = max(rowmax[i], grid[i][j]);
                colmax[j] = max(colmax[j], grid[i][j]);
            }
        }
        int res = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                res += min(rowmax[i], colmax[j])-grid[i][j];
            }
        }
        return res;
    }
};