//--- Q: 1765. Map of Highest Peak

//--- method 1: bfs
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row = isWater.size(), col = isWater[0].size();
        vector<vector<int>> dirs = {{1,0} ,{-1,0}, {0,1}, {0,-1}};
        queue<pair<int,int>> que;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (isWater[i][j]) {
                    isWater[i][j] = 0;
                    que.push({i,j});
                } else {
                    isWater[i][j] = -1;
                }
            }
        }
        int h = 1;
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                for (auto &dir: dirs) {
                    int nr = now.first+dir[0];
                    int nc = now.second+dir[1];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col || isWater[nr][nc] != -1) {
                        continue;
                    }
                    que.push({nr,nc});
                    isWater[nr][nc] = h;
                }
            }
            ++h;
        }
        return isWater;
    }
};
