//--- Q: 0463. Island Perimeter

//--- method 1: compute perimeter with subtracting duplicate side length
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int total = 0, remove = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j]) {
                    ++total;
                    if (i+1 < row && grid[i+1][j]) {
                        ++remove;
                    }
                    if (j+1 < col && grid[i][j+1]) {
                        ++remove;
                    }
                }
            }
        }
        return total*4-remove*2;
    }
};