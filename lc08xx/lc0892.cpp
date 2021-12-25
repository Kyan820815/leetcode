//--- Q: 0892. Surface Area of 3D Shapes

//--- method 1; count cubes, directly
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), res = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (!grid[i][j]) {
                    continue;
                }
                res += 2 + grid[i][j]*4;
                if (i+1 < row) {
                    res -= 2*min(grid[i][j],grid[i+1][j]);
                }
                if (j+1 < col) {
                    res -= 2*min(grid[i][j],grid[i][j+1]);
                }
            }
        }
        return res;
    }
};

//--- method 2: count cubes, clean
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), res = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (!grid[i][j]) {
                    continue;
                }
                res += 2 + grid[i][j]*4;
                if (i+1 < row) {
                    res -= 2*min(grid[i][j],grid[i+1][j]);
                }
                if (j+1 < col) {
                    res -= 2*min(grid[i][j],grid[i][j+1]);
                }
            }
        }
        return res;
    }
};