//--- Q: 0286. Walls and Gates

//--- method 1: bfs
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int row = rooms.size(), col = rooms[0].size();
        queue<pair<int,int>> que;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (!rooms[i][j]) {
                    que.push({i,j});
                }
            }
        }
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                for (auto &dir: dirs) {
                    int nr = now.first + dir[0];
                    int nc = now.second + dir[1];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col || rooms[nr][nc] != INT_MAX) {
                        continue;
                    }
                    rooms[nr][nc] = rooms[now.first][now.second]+1;
                    que.push({nr,nc});
                }
            }
        }
    }
};