//--- Q: 0980. Unique Paths III

//--- method 1: dfs
class Solution {
public:
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int res = 0, row, col;
    int uniquePathsIII(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();
        int cnt = 0, sr, sc, er, ec;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    sr = i, sc = j;
                } else if (grid[i][j] == 2) {
                    er = i, ec = j;
                }
                cnt += grid[i][j] != -1;
            }
        }
        dfs(sr, sc, er, ec, cnt-1, grid);
        return res;
    }
    void dfs(int r, int c, int er, int ec, int cnt, vector<vector<int>> &grid) {
        if (r == er && c == ec) {
            res += !cnt;
            return;
        }
        --cnt;
        auto tmp = grid[r][c];
        grid[r][c] = -1;
        for (auto &dir: dirs) {
            int nr = r+dir[0];
            int nc = c+dir[1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || grid[nr][nc] == -1) {
                 continue;
            }
            dfs(nr, nc, er, ec, cnt, grid);
        }
        grid[r][c] = tmp;
    }
};