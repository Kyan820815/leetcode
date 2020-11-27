//--- Q: 959. Regions Cut By Slashes

//--- method 1: union find
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        count = n * n * 4;
        for (int i = 0; i < n*n*4; ++i) {
            parent.push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) {
                    uni(upscale(i, j, 0, n), upscale(i-1, j, 2, n));
                }
                if (j > 0) {
                    uni(upscale(i, j, 3, n), upscale(i, j-1, 1, n));
                }
                if (grid[i][j] != '/') {
                    uni(upscale(i, j, 3, n), upscale(i, j, 2, n));
                    uni(upscale(i, j, 0, n), upscale(i, j, 1, n));
                }
                if (grid[i][j] != '\\') {
                    uni(upscale(i, j, 0, n), upscale(i, j, 3, n));
                    uni(upscale(i, j, 1, n), upscale(i, j, 2, n));
                }
            }
        }
        return count;
    }
    int findp(int now, vector<int> &parent) {
        if (parent[now] != now) {
            parent[now] = findp(parent[now], parent);
        }
        return parent[now];
    }
    void uni(int a, int b) {
        int ap = findp(a, parent);
        int bp = findp(b, parent);
        if (ap != bp) {
            parent[ap] = bp;
            --count;
        }
    }
    int upscale(int i, int j, int k, int n) {
        return (i * n + j) * 4 + k;
    }
    int count;
    vector<int> parent;
};

//--- method 2: upscale dfs
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size(), m = n*3, count = 0;
        upgrid.resize(m, vector<int>(m, 0));
        dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '/') {
                    upgrid[i*3+0][j*3+2] = 1;
                    upgrid[i*3+1][j*3+1] = 1;
                    upgrid[i*3+2][j*3+0] = 1;
                } else if (grid[i][j] =='\\') {
                    upgrid[i*3+0][j*3+0] = 1;
                    upgrid[i*3+1][j*3+1] = 1;
                    upgrid[i*3+2][j*3+2] = 1;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!upgrid[i][j]) {
                    ++count;
                    dfs(i, j, m);
                }
            }
        }
        return count;
    }
    void dfs(int r, int c, int m) {
        upgrid[r][c] = 1;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (nr < 0 || nr >= m || nc < 0 || nc >= m || upgrid[nr][nc]) {
                continue;
            }
            dfs(nr, nc, m);
        }
    }
    vector<vector<int>> dir, upgrid;
};