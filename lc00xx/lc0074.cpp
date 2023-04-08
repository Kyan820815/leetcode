//--- Q: 0074. Search a 2D Matrix
//--- last written: 2023/04/04

//--- method 1: binary search, O(logn)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int left = 0, right = row*col-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            int r = mid/col, c = mid%col;
            if (matrix[r][c] < target) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return matrix[left/col][left%col] == target;
    }
};
