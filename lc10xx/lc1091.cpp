//--- Q: 1091. Shortest Path in Binary Matrix

//--- method 1: bfs
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        queue<pair<int,int>> que;
        if (grid[0][0]) {
            return -1;
        }
        que.push({0,0});
        grid[0][0] = 1;
        int res = 1;
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                if (now.first == row-1 && now.second == col-1) {
                    return res;
                }
                for (auto &dir: dirs) {
                    int nr = dir[0]+now.first;
                    int nc = dir[1]+now.second;
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col || grid[nr][nc]) {
                        continue;
                    }
                    grid[nr][nc] = 1;
                    que.push({nr,nc});
                }
            }
            ++res;
        }
        return -1;
    }
};