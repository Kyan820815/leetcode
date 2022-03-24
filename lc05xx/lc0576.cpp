//--- Q: 0576. Out of Boundary Paths

//--- method 1: iteration rom boarder to start
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        vector<vector<int>> visit(m, vector<int>(n, 0));
        int mod = 1e9+7;
        if (!maxMove) {
            return 0;
        }
        for (int i = 0; i < m; ++i) {
            ++visit[i][0];
            ++visit[i][n-1];
        }
        for (int j = 0; j < n; ++j) {
            ++visit[0][j];
            ++visit[m-1][j];
        }
        int res = visit[startRow][startColumn];
        for (int i = 1; i < maxMove; ++i) {
            vector<vector<int>> tmp(m, vector<int>(n, 0));
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < n; ++k) {
                    for (auto &dir: dirs) {
                        int nr = j+dir[0];
                        int nc = k+dir[1];
                        if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                            continue;
                        }
                        tmp[nr][nc] = (tmp[nr][nc]+visit[j][k])%mod;
                    }
                }
            }
            visit = tmp;
            res = (res+visit[startRow][startColumn])%mod;
        }
        return res;
    }
};

//--- method 2: iteration from start to boarder
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        vector<vector<int>> visit(m, vector<int>(n, 0));
        int mod = 1e9+7;
        if (!maxMove) {
            return 0;
        }
        visit[startRow][startColumn] = 1;
        int res = 0;
        for (int i = 0; i < maxMove; ++i) {
            vector<vector<int>> tmp(m, vector<int>(n, 0));
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < n; ++k) {
                    for (auto &dir: dirs) {
                        int nr = j+dir[0];
                        int nc = k+dir[1];
                        if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                            res = (res+visit[j][k])%mod;
                        } else {
                            tmp[nr][nc] = (tmp[nr][nc]+visit[j][k])%mod;
                        }
                    }
                }
            }
            visit = tmp;
        }
        return res;
    }
};

//--- method 3: dfs recursion
class Solution {
public:
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int mod = 1e9+7, row, col;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        row = m, col = n;
        vector<vector<vector<int>>> visit(maxMove+1, vector<vector<int>>(m, vector<int>(n, -1)));
        return dfs(startRow, startColumn, maxMove, visit);
    }
    int dfs(int r, int c, int k, vector<vector<vector<int>>> &visit) {
        if (visit[k][r][c] != -1) {
            return visit[k][r][c];
        }
        int sum = 0;
        for (auto &dir: dirs) {
            int nr = r+dir[0];
            int nc = c+dir[1];
            if (k && (nr < 0 || nr >= row || nc < 0 || nc >= col)) {
                sum = (sum+1)%mod;
                continue;
            }
            if (k > 1) {
                sum = (sum + dfs(nr, nc, k-1, visit)) % mod;
            }
        }
        return visit[k][r][c] = sum;
    }
};
