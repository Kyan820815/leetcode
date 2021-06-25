//--- Q: 407. Trapping Rain Water II

//--- method 1: dijkstra
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int row = heightMap.size(), col = heightMap[0].size();
        vector<vector<int>> visit(row, vector<int>(col, 0));
        auto comp = [](vector<int> &a, vector<int> &b) {
            return a[2] > b[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> que(comp);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (!(!i || !j || i==row-1 || j==col-1)) {
                    continue;
                }
                que.push({i,j,heightMap[i][j]});
                visit[i][j] = 1;
            }
        }
        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int mh = 0, res = 0;
        while (que.size()) {
            auto node = que.top();
            que.pop();
            int r = node[0], c = node[1];
            mh = max(mh, node[2]);
            for (int i = 0; i < 4; ++i) {
                int nr = r+dir[i][0];
                int nc = c+dir[i][1];
                if (nr < 0 || nr >= row || nc < 0 || nc >= col || visit[nr][nc]) {
                    continue;
                }
                if (heightMap[nr][nc] < mh) {
                    res += mh-heightMap[nr][nc];
                }
                que.push({nr, nc, heightMap[nr][nc]});
                visit[nr][nc] = 1;
            }
        }
        return res;
    }
};