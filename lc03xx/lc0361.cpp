//--- Q: 0361. Bomb Enemy

//--- method 1: O(mn) space
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size(), res = 0;
        vector<int> cc(col, 0);
        vector<vector<int>> visit(row, vector<int>(col, 0));
        for (int i = 0; i < row; ++i) {
            int rc = 0;
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 'W') {
                    rc = cc[j] = 0;
                } else if (grid[i][j] == 'E') {
                    ++rc, ++cc[j];
                } else {
                    visit[i][j] = rc + cc[j];
                }
            }
        }
        fill(cc.begin(), cc.end(), 0);
        for (int i = row-1; i >= 0; --i) {
            int rc = 0;
            for (int j = col-1; j >= 0; --j) {
                if (grid[i][j] == 'W') {
                    rc = cc[j] = 0;
                } else if (grid[i][j] == 'E') {
                    ++rc, ++cc[j];
                } else {
                    res = max(res, visit[i][j]+rc+cc[j]);
                }
            }
        }
        return res;
    }
};

//--- method 2: O(m) space
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size(), res = 0;
        vector<int> cc(col, 0);
        for (int i = 0; i < row; ++i) {
            int rc = 0;
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 'W') {
                    rc = cc[j] = 0;
                } else {
                    if (!i || grid[i-1][j] == 'W') {
                        for (int k = i; k < row && grid[k][j] != 'W'; ++k) {
                            cc[j] += grid[k][j] == 'E';
                        }
                    }
                    if (!j || grid[i][j-1] == 'W') {
                        for (int k = j; k < col && grid[i][k] != 'W'; ++k) {
                            rc += grid[i][k] == 'E';
                        }
                    }
                    if (grid[i][j] == '0') {
                        res = max(res, rc+cc[j]);
                    }
                }
            }
        }
        return res;
    }
};