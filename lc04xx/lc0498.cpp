//--- Q: 0498. Diagonal Traverse

//--- method 1: find law of the problem
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int dir = -1, row = mat.size(), col = mat[0].size(), cnt = row*col;
        int r = 0, c = 0;
        while (cnt--) {
            res.push_back(mat[r][c]);
            int nr = r+dir, nc = c-dir;
            if (nr >= row) {
                ++c, dir *= -1;
            } else if (nc >= col) {
                ++r, dir *= -1;
            } else if (nr < 0) {
                ++c, dir *= -1;
            } else if (nc < 0) {
                ++r, dir *= -1;
            } else {
                r = nr, c = nc;
            }
        }
        return res;
    }
};

//--- follow up: top-right direction
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int dir = -1, row = mat.size(), col = mat[0].size(), cnt = row*col;
        int sr = 0, sc = 0, r = 0, c = 0;
        while (cnt--) {
            res.push_back(mat[r][c]);
            r += dir, c -= dir;
            if (r < 0 || c >= col) {
                if (sr < row-1) {
                    r = ++sr, c = sc;
                } else {
                    r = sr, c = ++sc;
                }
            }
        }
        return res;
    }
};

//--- follow up: bottom-left direction
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int dir = 1, row = mat.size(), col = mat[0].size(), cnt = row*col;
        int sr = 0, sc = 0, r = 0, c = 0;
        while (cnt--) {
            res.push_back(mat[r][c]);
            r += dir, c -= dir;
            if (c < 0 || r >= row) {
                if (sc < col-1) {
                    r = sr, c = ++sc;
                } else {
                    r = ++sr, c = sc;
                }
            }
        }
        return res;
    }
};
