//--- Q: 0994. Rotting Oranges

//--- method 1: bfs
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), res = 0, orange = 0;
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        queue<pair<int,int>> que;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    ++orange;
                } else if (grid[i][j] == 2) {
                    que.push({i,j});
                }
            }
        }
        if (!orange) {
            return res;
        }
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                for (auto &dir: dirs) {
                    int nr = now.first+dir[0];
                    int nc = now.second+dir[1];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col || grid[nr][nc] != 1) {
                        continue;
                    }
                    if (!--orange) {
                        return res+1;
                    }
                    grid[nr][nc] = 2;
                    que.push({nr,nc});
                }
            }
            ++res;
        }
        return -1;
    }
};