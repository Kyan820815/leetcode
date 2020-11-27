//--- Q: 994. Rotting Oranges

//--- method 1: bfs
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> que;
        vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int cnt = 0;
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 2) {
                    que.push({i, j});
                } else if (grid[i][j] == 1) {
                    ++cnt;
                }
            }
        }
        int res = -1;
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                for (int j = 0; j < 4; ++j) {
                    int ni = dir[j][0] + now.first;
                    int nj = dir[j][1] + now.second;
                    if (ni < 0 || ni >= row || nj < 0 || nj >= col || grid[ni][nj] != 1) {
                        continue;
                    }
                    grid[ni][nj] = 2;
                    --cnt;
                    que.push({ni, nj});
                }
            }
            ++res;
        }
        return !cnt ? (res == -1 ? 0 : res) : -1;
    }
};