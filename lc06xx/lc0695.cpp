//--- Q: 0695. Max Area of Island

//--- method 1: dfs
class Solution {
public:
    int row, col;
    vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j]) {
                    int cnt = 0;
                    dfs(i, j, cnt, grid);
                    res = max(res, cnt);
                }
            }
        }
        return res;
    }
    void dfs(int r, int c, int &cnt, vector<vector<int>> &grid) {
        ++cnt;
        grid[r][c] = 0;
        for (auto &dir: dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || !grid[nr][nc]) {
                continue;
            }
            dfs(nr, nc, cnt, grid);
        }
    }
};

//--- method 2: union find
class Solution {
public:
    vector<int> parent, cnt;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        parent.resize(row*col, -1);
        cnt.resize(row*col, 0);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j]) {
                    int ap = findp(i*col+j);
                    for (auto &dir: dirs) {
                        int nr = i + dir[0];
                        int nc = j + dir[1];
                        if (nr < 0 || nr >= row || nc < 0 || nc >= col || !grid[nr][nc]) {
                            continue;
                        }
                        int bp = findp(nr*col+nc);
                        if (ap != bp) {
                            if (cnt[ap] < cnt[bp]) {
                                parent[ap] = parent[bp];
                                cnt[bp] += cnt[ap];
                                cnt[ap] = 0;
                            } else {
                                parent[bp] = parent[ap];
                                cnt[ap] += cnt[bp];
                                cnt[bp] = 0;
                            }
                        }
                        ap = findp(i*col+j);
                    }
                }
            }
        }
        int tcnt = row*col, res = 0;
        for (int i = 0; i < tcnt; ++i) {
            res = max(res, cnt[i]);
        }
        return res;
    }
    int findp(int now) {
        if (parent[now] == -1) {
            cnt[now] = 1;
            return parent[now] = now;
        } else if (parent[now] == now) {
            return now;
        } else {
            return parent[now] = findp(parent[now]);
        }
    }
};