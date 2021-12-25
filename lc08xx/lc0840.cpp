//--- Q: 0840. Magic Squares In Grid

//--- method 1: brute force
class Solution {
public:
    int row, col;
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();
        int res = 0;
        for (int i = 0; i < row-2; ++i) {
            for (int j = 0; j < col-2; ++j) {
                res += valid(i, j, grid);
            }
        }
        return res;
    }
    bool valid(int r, int c, vector<vector<int>> &grid) {
        vector<int> cnt(10, 0), colsum(col, 0);
        int sum = 0;
        for (int j = 0; j < 3; ++j) {
            if (!grid[r][c+j] || grid[r][c+j] > 9 || ++cnt[grid[r][c+j]] > 1) {
                return false;
            }
            colsum[j] += grid[r][c+j];
            sum += grid[r][c+j];
        }
        for (int i = 1; i < 3; ++i) {
            int tmp = 0;
            for (int j = 0; j < 3; ++j) {
                if (!grid[r+i][c+j] || grid[r+i][c+j] > 9 || ++cnt[grid[r+i][c+j]] > 1) {
                    return false;
                }
                colsum[j] += grid[r+i][c+j];
                tmp += grid[r+i][c+j];
            }
            if (tmp != sum) {
                return false;
            }
        }
        for (int j = 0; j < 3; ++j) {
            if (sum != colsum[j]) {
                return false;
            }
        }
        if (grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2] != sum || grid[r+2][c]+grid[r+1][c+1]+grid[r][c+2] != sum) {
            return false;
        }
        return true;
    }
};