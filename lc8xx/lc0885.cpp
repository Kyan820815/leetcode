//--- Q: Spiral Matrix III

//--- method 1: boundary condition
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int cnt = R*C-1, hor = 1, ver = 1, now;
        vector<vector<int>> res;
        res.push_back({r0, c0});
        
        while (cnt) {
            // right
            now = hor++;
            while (now--) {
                c0++;
                if (c0 < C && c0 >= 0 && r0 < R && r0 >= 0) {
                    res.push_back({r0, c0});
                    if (!--cnt)
                        break;
                }
            }
            if (!cnt)
                break;
            
            // down
            now = ver++;
            while (now--) {
                r0++;
                if (c0 < C && c0 >= 0 && r0 < R && r0 >= 0) {
                    res.push_back({r0, c0});
                    if (!--cnt)
                        break;
                }
            }
            if (!cnt)
                break;
            
            // left
            now = hor++;
            while (now--) {
                c0--;
                if (c0 < C && c0 >= 0 && r0 < R && r0 >= 0) {
                    res.push_back({r0, c0});
                    if (!--cnt)
                        break;
                }
            }
            if (!cnt)
                break;

            // up
            now = ver++;
            while (now--) {
                r0--;
                if (c0 < C && c0 >= 0 && r0 < R && r0 >= 0) {
                    res.push_back({r0, c0});
                    if (!--cnt)
                        break;
                }
            }
            if (!cnt)
                break;

        }
        return res;
    }
};