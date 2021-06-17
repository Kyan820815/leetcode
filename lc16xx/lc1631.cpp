//--- Q: 1631. Path With Minimum Effort

//--- method 1-1: dijkstra
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
        auto comp = [&dist](pair<int,int> &a, pair<int,int> &b) {
            return dist[a.first][a.second] > dist[b.first][b.second];
        };
        dist[0][0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> que(comp);
        que.push({0,0});
        while (que.size()) {
            auto now = que.top();
            que.pop();
            int r = now.first, c = now.second;
            for (int i = 0; i < 4; ++i) {
                int nr = r+dir[i][0];
                int nc = c+dir[i][1];
                if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
                    continue;
                }
                int val = max(dist[r][c], abs(heights[r][c]-heights[nr][nc]));
                if (val < dist[nr][nc]) {
                    dist[nr][nc] = val;
                    que.push({nr, nc});
                }
            }
        }
        return dist[row-1][col-1];
    }
};

//--- method 1-2: anther dijkstra
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
        auto comp = [](vector<int> &a, vector<int> &b) {
            return a[2] > b[2];
        };
        dist[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> que(comp);
        que.push({0,0, 0});
        while (que.size()) {
            auto now = que.top();
            que.pop();
            int r = now[0], c = now[1];
            if (r == row-1 && c == col-1) {
                return now[2];
            }
            for (int i = 0; i < 4; ++i) {
                int nr = r+dir[i][0];
                int nc = c+dir[i][1];
                if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
                    continue;
                }
                int val = max(now[2], abs(heights[r][c]-heights[nr][nc]));
                if (val < dist[nr][nc]) {
                    dist[nr][nc] = val;
                    que.push({nr, nc, val});
                }
            }
        }
        return -1;
    }
};