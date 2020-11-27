//--- Q: 1391. Check if There is a Valid Path in a Grid

//--- method 1: bfs
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dir = {{{0,-1},{0,1}}, {{-1,0},{1,0}}, {{0,-1},{1,0}},
                                          {{0,1},{1,0}}, {{-1,0},{0,-1}}, {{-1,0},{0,1}}};
        queue<pair<int,int>> que{{{0,0}}};
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> visit(row, vector<int>(col, 0));
        visit[0][0] = 1;
        while (que.size()) {
            auto now = que.front();
            que.pop();
            int type = grid[now.first][now.second]-1;
            for (int i = 0; i < dir[type].size(); ++i) {
                int nr = now.first + dir[type][i][0];
                int nc = now.second + dir[type][i][1];
                if (nr < 0 || nr >= row || nc < 0 || nc >= col || visit[nr][nc]) {
                    continue;
                }
                int back_type = grid[nr][nc]-1;
                for (int j = 0; j < dir[back_type].size(); ++j) {
                    int r = nr + dir[back_type][j][0];
                    int c = nc + dir[back_type][j][1];
                    if (r == now.first && c == now.second) {
                        visit[nr][nc] = 1;
                        que.push({nr, nc});
                        break;
                    }
                }
            }
        }
        return visit[row-1][col-1];
    }
};