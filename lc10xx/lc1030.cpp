//--- Q: 1030. Matrix Cells in Distance Order

//--- method 1: bfs
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res, visit(R, vector<int>(C, 0)), dir = {{-1,0},{1,0}, {0,-1},{0,1}};
        queue<pair<int, int>> que;
        visit[r0][c0] = 1;
        que.push({r0, c0});
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                res.push_back({now.first, now.second});
                for (int j = 0; j < 4; ++j) {
                    int nr = now.first + dir[j][0];
                    int nc = now.second + dir[j][1];
                    if (nr < 0 || nr >= R || nc < 0 || nc >= C || visit[nr][nc]) {
                        continue;
                    }
                    visit[nr][nc] = 1;
                    que.push({nr, nc});
                }
            }
        }
        return res;
    }
};
