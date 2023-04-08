//--- Q: 0054. Spiral Matrix
//--- last written: 2023/03/15

//--- method 1: clean code use dir
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<int> res;
        int r = 0, c = 0, row = matrix.size(), col = matrix[0].size(), d = 0;
        int cnt = row*col;
        while (cnt--) {
            res.push_back(matrix[r][c]);
            matrix[r][c] = -101;
            int nr = r+dirs[d][0];
            int nc = c+dirs[d][1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || matrix[nr][nc] == -101) {
                d = (d+1)%4;
                r += dirs[d][0], c += dirs[d][1];
            } else {
                r = nr, c = nc;
            }
        }
        return res;
    }
};

//--- method 2: iter, not revise input matrix
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int r = 0, c = -1, total = row*col, idx = 0;
        vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<int> shift = {col, row-1}, res;
        while (total) {
            for (int i = 0; i < 4 && total; ++i) {
                int cnt = shift[idx]--;
                total -= cnt;
                while (cnt--) {
                    r += dirs[i][0];
                    c += dirs[i][1];
                    res.push_back(matrix[r][c]);
                }
                idx ^= 1;
            }
        }
        return res;
    }
};
