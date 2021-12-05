//--- Q: 0562. Longest Line of Consecutive One in Matrix

//--- method 1: O(1) space linear process
class Solution {
public:
    int row, col;
    int longestLine(vector<vector<int>>& mat) {
        int res = 0;
        row = mat.size(), col = mat[0].size();
        vector<vector<int>> dirs = {{0,1},{1,0},{1,1},{1,-1}};
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (!mat[i][j]) {
                    continue;
                }
                for (auto &dir: dirs) {
                    int r = i, c = j;
                    if (out_of_bound(r-dir[0],c-dir[1]) || !mat[r-dir[0]][c-dir[1]]) {
                        int cnt = 1;
                        while (!out_of_bound(r+dir[0],c+dir[1]) && mat[r+dir[0]][c+dir[1]]) {
                            ++cnt;
                            r += dir[0], c += dir[1];
                        }
                        res = max(res, cnt);
                    }
                }
            }
        }
        return res;
    }
    bool out_of_bound(int r, int c) {
        return r < 0 || r >= row || c < 0 || c >= col;
    }
};

//--- method 2: O(n) space
class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size(), res = 0;
        vector<int> rcnt(row, 0), ccnt(col, 0), dig(row+col-1, 0), idig(row+col-1, 0);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (!mat[i][j]) {
                    rcnt[i] = ccnt[j] = dig[i-j+col-1] = idig[i+j] = 0;
                } else {
                    ++rcnt[i], ++ccnt[j], ++dig[i-j+col-1], ++idig[i+j];
                    res = max(res, max(rcnt[i], ccnt[j]));
                    res = max(res, max(dig[i-j+col-1], idig[i+j]));
                }
            }
        }
        return res;
    }
};