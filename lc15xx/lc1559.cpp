//--- Q: 1559. Detect Cycles in 2D Grid

//--- method 1: dfs
class Solution {
public:
    int row, col;
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    bool containsCycle(vector<vector<char>>& grid) {
        row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (islower(grid[i][j])) {
                    if (dfs(i, j, -1, -1, grid)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool dfs(int r, int c, int pr, int pc, vector<vector<char>> &grid) {
        grid[r][c] ^= 32;
        for (auto &dir: dirs) {
            int nr = r+dir[0];
            int nc = c+dir[1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
                continue;
            }
            if (grid[nr][nc] == grid[r][c] && (nr != pr || nc != pc)) {
                return true;
            }
            if ((grid[nr][nc]^32) == grid[r][c]) {
                if (dfs(nr, nc, r, c, grid)) {
                    return true;
                }
            }
        }
        return false;
    }
};

//--- method 2: union find
class Solution {
public:
    int row, col;
    vector<int> parent;
    bool containsCycle(vector<vector<char>>& grid) {
        row = grid.size(), col = grid[0].size();
        parent.resize(row*col, -1);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (i && j && findp((i-1)*col+j) == findp(i*col+j-1) 
                    && grid[i-1][j] == grid[i][j-1] && grid[i-1][j] == grid[i][j]) {
                    return true;
                }
                if (i && grid[i-1][j] == grid[i][j]) {
                    int ap = findp((i-1)*col+j);
                    int bp = findp(i*col+j);
                    if (ap != bp) {
                        if (-parent[ap] > -parent[bp]) {
                            swap(ap, bp);
                        }
                        parent[bp] += parent[ap];
                        parent[ap] = bp;
                    }
                }
                if (j && grid[i][j-1] == grid[i][j]) {
                    int ap = findp(i*col+j-1);
                    int bp = findp(i*col+j);
                    if (ap != bp) {
                        if (-parent[ap] > -parent[bp]) {
                            swap(ap, bp);
                        }
                        parent[bp] += parent[ap];
                        parent[ap] = bp;
                    }
                }
            }
        }
        return false;
    }
    int findp(int now) {
        if (parent[now] == now) {
            return now;
        } else if (parent[now] < 0) {
            return now;
        } else {
            return parent[now] = findp(parent[now]);
        }
    }
};