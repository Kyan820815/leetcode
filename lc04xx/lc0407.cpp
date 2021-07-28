//--- Q: 0407. Trapping Rain Water II

//--- method 1: dijkstra
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int row = heightMap.size(), col = heightMap[0].size(), res = 0;
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}}, visit(row, vector<int>(col, 0));
        auto comp = [](pair<int,int> &a, pair<int,int> &b) {
            return a.second > b.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> que(comp);
        for (int i = 0; i < row; ++i) {
            visit[i][0] = visit[i][col-1] = 1;
            que.push({i*col,heightMap[i][0]});
            que.push({i*col+col-1,heightMap[i][col-1]});
        }
        for (int j = 0; j < col; ++j) {
            visit[0][j] = visit[row-1][j] = 1;
            que.push({j, heightMap[0][j]});
            que.push({(row-1)*col+j, heightMap[row-1][j]});
        }
        int maxv = 0;
        while (que.size()) {
            auto now = que.top();
            que.pop();
            if (maxv > now.second) {
                res += maxv-now.second;
            } else {
                maxv = now.second;
            }
            int r = now.first/col, c = now.first%col;
            for (auto &dir: dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if (nr < 0 || nr >= row || nc < 0 || nc >= col || visit[nr][nc]) {
                    continue;
                }
                visit[nr][nc] = 1;
                que.push({nr*col+nc, heightMap[nr][nc]});
            }
        }
        return res;
    }
};