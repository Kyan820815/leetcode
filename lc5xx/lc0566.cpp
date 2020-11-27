//--- Q: 566. Reshape the Matrix

//--- method 1: O(n*m)
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row = nums.size(), col = nums[0].size();
        if (row*col != r*c) {
            return nums;
        }
        vector<vector<int>> res(r, vector<int>(c, 0));
        int idx = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                int ri = idx/col, ci = idx%col;
                res[i][j] = nums[ri][ci];
                ++idx;
            }
        }
        return res;
    }
};