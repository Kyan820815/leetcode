//--- Q: 1091. Shortest Path in Binary Matrix

//--- method 1: bfs
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
        if (grid[0][0]) {
            return -1;
        }
        grid[0][0] = 1;
        int res = 1, row = grid.size(), col = grid[0].size();
        queue<pair<int, int>> que;
        que.push({0,0});
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                if (now.first == row-1 && now.second == col-1) {
                    return res;
                }
                for (int j = 0; j < 8; ++j) {
                    int nr = now.first+dir[j][0];
                    int nc = now.second+dir[j][1];
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