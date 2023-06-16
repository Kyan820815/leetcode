//--- Q: 0059. Spiral Matrix II
//--- last written: 2023/06/16

//--- method 1: clean code
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0)), dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<int> shift = {n, n-1};
        int idx = 0, total = n*n, val = 1, r = 0, c = -1;
        while (total) {
            for (int i = 0; i < 4 && total; ++i) {
                int cnt = shift[idx]--;
                total -= cnt;
                while (cnt--) {
                    r += dirs[i][0];
                    c += dirs[i][1];
                    res[r][c] = val++;
                }
                idx ^= 1;
            }
        }
        return res;
    }
};
