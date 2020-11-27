//--- Q: 1351. Count Negative Numbers in a Sorted Matrix

//--- method 1: O(m+n)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int res = 0, i = 0, j = col-1;
        while (i < row && j >= 0) {
            if (grid[i][j] < 0) {
                res += row-i;
                --j;
            } else {
                ++i;
            }
        }
        return res;
    }
};