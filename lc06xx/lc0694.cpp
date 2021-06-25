//--- 694. Number of Distinct Islands

//--- method 1: dfs
class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> set;
        vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int row = grid.size(), col = grid[0].size() ;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j]) {
                    string now = "0";
                    dfs(i, j, grid, dir, now);
                    if (set.find(now) == set.end()) {
                        set.insert(now);
                    }
                }
            }
        }
        return set.size();
    }
    void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &dir, string &now) {
        int row = grid.size(), col = grid[0].size();
        grid[r][c] = 0;
        for (int i = 0; i < 4; ++i) {
            int next_r = r + dir[i][0];
            int next_c = c + dir[i][1];
            if (next_r < 0 || next_r >= row || next_c < 0 || next_c >= col || !grid[next_r][next_c])
                continue;
            now = now + " " + to_string(i);
            dfs(next_r, next_c, grid, dir, now);
        }
        now.push_back('b');
    }
};