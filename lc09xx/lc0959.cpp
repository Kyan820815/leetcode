//--- Q: 0959. Regions Cut By Slashes

//--- method 1: union find
cclass Solution {
public:
    vector<int> parent;
    int regionsBySlashes(vector<string>& grid) {
        int row = grid.size(), col = grid[0].size(), res = 4*row*col;
        parent.resize(row*col*4, -1);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int idx = (i*col+j)*4;
                if (grid[i][j] != '/') {
                    int ap = findp(idx);
                    int bp = findp(idx+1);
                    if (ap != bp) {
                        parent[ap] = bp;
                        --res;
                    }
                    ap = findp(idx+2);
                    bp = findp(idx+3);
                    if (ap != bp) {
                        parent[ap] = bp;
                        --res;
                    }
                }
                if (grid[i][j] != '\\') {
                    int ap = findp(idx);
                    int bp = findp(idx+3);
                    if (ap != bp) {
                        parent[ap] = bp;
                        --res;
                    }
                    ap = findp(idx+1);
                    bp = findp(idx+2);
                    if (ap != bp) {
                        parent[ap] = bp;
                        --res;
                    }
                }
                if (j+1 < col) {
                    int ap = findp(idx+1);
                    int bp = findp(idx+1+6);
                    if (ap != bp) {
                        parent[ap] = bp;
                        --res;
                    }
                }
                if (i+1 < row) {
                    int ap = findp(idx+2);
                    int bp = findp(idx+col*4);
                    if (ap != bp) {
                        parent[ap] = bp;
                        --res;
                    }
                }
            }
        }
        return res;
    }
    int findp(int now) {
        if (parent[now] == now) {
            return now;
        } else {
            return parent[now] = parent[now] == -1 ? now : findp(parent[now]);
        }
    }
};

//--- method 2: upscale dfs
class Solution {
public:
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int row, col;
    int regionsBySlashes(vector<string>& grid) {
        row = grid.size(), col = grid[0].size();
        int res = 0;
        vector<vector<int>> tmp(row*3, vector<int>(col*3, 0));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '/') {
                    tmp[i*3+2][j*3] = 1;
                    tmp[i*3+1][j*3+1] = 1;
                    tmp[i*3][j*3+2] = 1;
                } else if (grid[i][j] == '\\') {
                    tmp[i*3][j*3] = 1;
                    tmp[i*3+1][j*3+1] = 1;
                    tmp[i*3+2][j*3+2] = 1;
                }
            }
        }
        for (int i = 0; i < row*3; ++i) {
            for (int j = 0; j < col*3; ++j) {
                if (!tmp[i][j]) {
                    dfs(i, j, tmp);
                    ++res;
                }
            }
        }
        return res;
    }
    void dfs(int r, int c, vector<vector<int>> &tmp) {
        tmp[r][c] = 1;
        for (auto &dir: dirs) {
            int nr = r+dir[0];
            int nc = c+dir[1];
            if (nr < 0 || nr >= row*3 || nc < 0 || nc >= col*3 || tmp[nr][nc]) {
                continue;
            }
            dfs(nr, nc, tmp);
        }
    }
};