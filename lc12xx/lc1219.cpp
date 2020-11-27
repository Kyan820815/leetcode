//--- Q: 1219. Path with Maximum Gold

//--- method 1: dfs
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), res = 0;
        vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j]) {
                    int last = grid[i][j];
                    grid[i][j] = 0;
                    dfs(i, j, grid, res, last, dir);
                    grid[i][j] = last;
                }
            }
        }
        return res;
    }
    void dfs(int r, int c, vector<vector<int>> &grid, int &res, int now, vector<vector<int>> &dir) {
        int row = grid.size(), col = grid[0].size();
        res = max(res, now);
        for (int i = 0; i < 4; ++i) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || !grid[nr][nc])
                continue;
            int last = grid[nr][nc];
            grid[nr][nc] = 0;
            dfs(nr, nc, grid, res, now+last, dir);
            grid[nr][nc] = last;
        }
    }
};