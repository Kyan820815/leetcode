//--- Q: 1293. Shortest Path in a Grid with Obstacles Elimination

//--- method 1: dijkstra
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int row = grid.size(), col = grid[0].size();
        if (k > row-1+col-1-1) {
            return row+col-2;
        }
        auto comp = [](vector<int> &a, vector<int> &b) {
            return a[2] > b[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> que(comp);
        vector<vector<vector<int>>> dist(k+1, vector<vector<int>>(row, vector<int>(col, INT_MAX)));
        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        dist[k][0][0] = 0;
        que.push({0,0,0,k});
        while (que.size()) {
            auto now = que.top();
            que.pop();
            int r = now[0], c = now[1], dis = now[2], times = now[3];
            if (r == row-1 && c == col-1) {
                return dis;
            }
            for (int i = 0; i < 4; ++i) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if (nr < 0 || nr >= row || nc < 0 || nc >= col || grid[nr][nc] && !times) {
                    continue;
                }
                int next_dis = dis+1;
                int next_times = times - (grid[nr][nc] == 1);
                if (next_dis < dist[next_times][nr][nc]) {
                    dist[next_times][nr][nc] = next_dis;
                    que.push({nr, nc, next_dis, next_times});
                }
            }
        }
        return -1;
    }
};

//--- method 2: bfs
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int row = grid.size(), col = grid[0].size();
        if (k > row-1+col-1-1) {
            return row+col-2;
        }
        vector<vector<vector<int>>> dist(k+1, vector<vector<int>>(row, vector<int>(col, INT_MAX)));
        queue<vector<int>> que;
        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        dist[k][0][0] = 0;
        que.push({0,0,k});
        while (que.size()) {
            int qsize = que.size();
                while (qsize--) {
                auto now = que.front();
                que.pop();
                int r = now[0], c = now[1], times = now[2];
                if (r == row-1 && c == col-1) {
                    return dist[times][r][c];
                }
                for (int i = 0; i < 4; ++i) {
                    int nr = r + dir[i][0];
                    int nc = c + dir[i][1];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col || grid[nr][nc] && !times) {
                        continue;
                    }
                    int next_dis = dist[times][r][c]+1;
                    int next_times = times - (grid[nr][nc] == 1);
                    if (next_dis < dist[next_times][nr][nc]) {
                        dist[next_times][nr][nc] = next_dis;
                        que.push({nr, nc, next_times});
                    }
                }
            }
        }
        return -1;
    }
};