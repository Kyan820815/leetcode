//--- Q: 1102. Path With Maximum Minimum Value

//--- method 1: Dijkstra
class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        auto comp = [](pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b) {
            return a.first < b.first;
        };
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, decltype(comp)> que(comp);
        que.push({grid[0][0],{0,0}});
        grid[0][0] = -1;
        while (que.size()) {
            auto now = que.top();
            que.pop();
            int val = now.first, r = now.second.first, c = now.second.second;
            if (r == row-1 && c == col-1) {
                return val;
            }
            for (auto &dir: dirs) {
                int nr = r+dir[0];
                int nc = c+dir[1];
                if (nr < 0 || nr >= row || nc < 0 || nc >= col || grid[nr][nc] == -1) {
                    continue;
                }
                int nval = min(val, grid[nr][nc]);
                que.push({nval,{nr,nc}});
                grid[nr][nc] = -1;
            }
        }
        return -1;
    }
};

//--- method 2: bfs
class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        vector<vector<int>> visit(row, vector<int>(col, INT_MIN));
        queue<pair<int,pair<int,int>>> que;
        que.push({grid[0][0],{0,0}});
        visit[0][0] = grid[0][0];
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                int val = now.first, r = now.second.first, c = now.second.second;
                for (auto &dir: dirs) {
                    int nr = r+dir[0];
                    int nc = c+dir[1];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
                        continue;
                    }
                    int nval = min(val, grid[nr][nc]);
                    if (nval > visit[nr][nc]) {
                        visit[nr][nc] = nval;
                        que.push({nval,{nr,nc}});
                    }
                }
            }
        }
        return visit[row-1][col-1];
    }
};