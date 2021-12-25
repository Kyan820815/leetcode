//--- Q: 0807. Max Increase to Keep City Skyline

//--- method 1: find max of row & col than compute diff
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<int> hor(row, 0), ver(col, 0);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                hor[i] = max(hor[i], grid[i][j]);
                ver[j] = max(ver[j], grid[i][j]);
            }
        }
        int sum = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                sum += min(hor[i], ver[j])-grid[i][j];
            }
        }
        return sum;
    }
};