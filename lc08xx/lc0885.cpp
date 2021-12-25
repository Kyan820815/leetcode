//--- Q: 0885. Spiral Matrix III

//--- method 1: boundary condition
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res = {{rStart, cStart}}, dirs = {{0,1},{1,0}};
        int cnt = rows*cols-1, r = rStart, c = cStart, sign = 1, len = 1;
        while (cnt) {
            for (auto &dir: dirs) {
                for (int i = 0; i < len; ++i) {
                    r += dir[0]*sign;
                    c += dir[1]*sign;
                    if (r >= 0 && r < rows && c >= 0 && c < cols) {
                        res.push_back({r,c});
                        cnt--;
                    }
                }
            }
            ++len, sign *= -1;
        }
        return res;
    }
};