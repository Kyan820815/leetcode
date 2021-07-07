//--- Q: 0200. Number of Islands

//--- method 1: dfs
class Solution {
public:
    int row, col;
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '1') {
                    ++res;
                    dfs(i, j, grid);
                }
            }
        }
        return res;
    }
    void dfs(int r, int c, vector<vector<char>> &grid) {
        grid[r][c] = '0';
        for (auto &dir: dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || grid[nr][nc] == '0') {
                continue;
            }
            dfs(nr, nc, grid);
        }
    }
};

//--- method 2: bfs
class Solution {
public:
    int row, col;
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '1') {
                    ++res;
                    bfs(i, j, grid);
                }
            }
        }
        return res;
    }
    void bfs(int r, int c, vector<vector<char>> &grid) {
        queue<pair<int,int>> que;
        que.push({r,c});
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                r = que.front().first, c = que.front().second;
                que.pop();
                for (auto &dir: dirs) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col || grid[nr][nc] == '0') {
                        continue;
                    }
                    grid[nr][nc] = '0';
                    que.push({nr,nc});
                }
            }
        }
        
    }
};