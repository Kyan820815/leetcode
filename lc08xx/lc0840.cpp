//--- Q: 840. Magic Squares In Grid

//--- method 1: brute force
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res = 0, row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row-2; ++i) {
            for (int j = 0; j < col-2; ++j) {
                if (magic(i, j, grid)) {
                    ++res;
                }
            }
        }
        return res;
    }
    bool magic(int r, int c, vector<vector<int>> &grid) {
        int spec = 0;
        vector<int> cnt(10, 0);
        for (int j = c; j < c+3; ++j) {
            if (!grid[r][j] || grid[r][j] > 9 || ++cnt[grid[r][j]] > 1) {
                return false;
            }
            spec += grid[r][j];      
        }
        for (int i = r+1; i < r+3; ++i) {
            int tmp = 0;
            for (int j = c; j < c+3; ++j) {
                if (!grid[i][j] || grid[i][j] > 9 || ++cnt[grid[i][j]] > 1) {
                    return false;
                }
                tmp += grid[i][j];
            }
            if (tmp != spec) {
                return false;
            }
        }
        for (int j = c; j < c+3; ++j) {
            int tmp = 0;
            for (int i = r; i < r+3; ++i) {
                tmp += grid[i][j];
            }
            if (tmp != spec) {
                return false;
            }
        }
        if (spec != grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2]) {
            return false;
        }
        if (spec != grid[r+2][c] + grid[r+1][c+1] + grid[r][c+2]) {
            return false;
        }
        return true;
    }
};