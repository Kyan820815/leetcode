//--- Q: 1030. Matrix Cells in Distance Order

//--- method 1: bfs
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> res, visit(rows, vector<int>(cols, 0)), dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        visit[rCenter][cCenter] = 1;
        queue<pair<int,int>> que;
        que.push({rCenter, cCenter});
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                res.push_back({now.first,now.second});
                for (auto &dir: dirs) {
                    int nr = now.first+dir[0];
                    int nc = now.second+dir[1];
                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || visit[nr][nc]) {
                        continue;
                    }
                    visit[nr][nc] = 1;
                    que.push({nr,nc});
                }
            }
        }
        return res;
    }
};