//--- Q: 1905. Count Sub Islands

//--- method 1: dfs recursion
class Solution {
public:
    int row, col, res;
    vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        row = grid1.size(), col = grid1[0].size(), res = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid2[i][j] && dfs(i, j, grid1, grid2)) {
                    ++res;
                }
            }
        }
        return res;
    }
    bool dfs(int r, int c, vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
        if (!grid1[r][c]) {
            return false;
        }
        grid2[r][c] = 0;
        bool find = true;
        for (auto &dir: dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || !grid2[nr][nc]) {
                continue;
            }
            find &= dfs(nr, nc, grid1, grid2);
        }
        return find;
    }
};