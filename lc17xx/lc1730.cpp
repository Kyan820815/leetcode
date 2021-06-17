//--- Q: 1730. Shortest Path to Get Food

//--- method 1: bfs
class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size(), sr, sc;
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        queue<pair<int,int>> que;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '*') {
                    sr = i, sc = j;
                }
            }
        }
        que.push({sr,sc});
        int res = 0;
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                for (auto &dir: dirs) {
                    int nr = now.first+dir[0];
                    int nc = now.second+dir[1];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col || grid[nr][nc] == 'X') {
                        continue;
                    }
                    if (grid[nr][nc] == '#') {
                        return res+1;
                    } else {
                        grid[nr][nc] = 'X';
                        que.push({nr,nc});
                    }
                }
            }
            ++res;
        }
        return -1;
    }
};