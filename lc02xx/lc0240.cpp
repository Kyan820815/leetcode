//--- Q: 0240. Search a 2D Matrix II

//--- method 1: linear search, O(n), better
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int r = 0, c = col-1;
        while (r < row && c >= 0) {
            if (matrix[r][c] > target) {
                --c;
            } else if (matrix[r][c] < target) {
                ++r;
            } else {
                return true;
            }
        }
        return false;
    }
};