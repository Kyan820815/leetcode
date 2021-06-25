//--- Q: 505. The Maze II

//--- method 1: bfs + Dijkstra
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int row = maze.size(), col = maze[0].size();
        vector<vector<int>> dis(row, vector<int>(col, INT_MAX));
        auto comp = [&dis](pair<int, int> &a, pair<int, int> &b) {
            return dis[a.first][a.second] > dis[b.first][b.second];
        };
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> que(comp);
        dis[start[0]][start[1]] = 0;
        maze[start[0]][start[1]] = 2;
        que.push({start[0], start[1]});
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.top();
                que.pop();
                for (int j = 0; j < 4; ++j) {
                    int nowr = now.first, nowc = now.second, d = dis[nowr][nowc];
                    while (canMove(nowr+dir[j][0], nowc+dir[j][1], row, col, maze)) {
                        nowr += dir[j][0];
                        nowc += dir[j][1];
                        ++d;
                    }
                    if (dis[nowr][nowc] > d) {
                        dis[nowr][nowc] = d;
                        que.push({nowr, nowc});
                        maze[nowr][nowc] = 2;
                    }
                }
            }
        }
        return dis[destination[0]][destination[1]] == INT_MAX ? -1 : dis[destination[0]][destination[1]];
    }
    bool canMove(int r, int c, int row, int col, vector<vector<int>> &maze) {
        return r >= 0 && r < row && c >= 0 && c < col && maze[r][c] != 1;
    }
};

//--- method 2: bfs
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        row = maze.size(), col = maze[0].size();
        vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        vector<vector<int>> dis_grid(row, vector<int>(col, INT_MAX));
        queue<pair<int,int>> que;
        que.push({start[0], start[1]});
        dis_grid[start[0]][start[1]] = 0;
        while (que.size()) {
            auto now = que.front();
            que.pop();
            for (int d = 0; d < 4; ++d) {
                int i = now.first, j = now.second, cur_dis = dis_grid[now.first][now.second];
                while (inBound(i+dir[d][0], j+dir[d][1]) && maze[i+dir[d][0]][j+dir[d][1]] == 0) {
                    ++cur_dis;
                    i += dir[d][0];
                    j += dir[d][1];
                }
                if (cur_dis < dis_grid[i][j]) {
                    dis_grid[i][j] = cur_dis;
                    que.push({i,j});
                }
            }
        }
        return dis_grid[destination[0]][destination[1]] == INT_MAX ?
                -1 : dis_grid[destination[0]][destination[1]];
    }
    bool inBound(int r, int c) {
        return r >= 0 && r < row && c >= 0 && c < col;
    }
    int row, col;
};

//--- method 3: dfs
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        dst = destination;
        grid = maze;
        row = maze.size(), col = maze[0].size();
        dis_grid.resize(row, vector<int>(col, INT_MAX));
        dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        dis_grid[start[0]][start[1]] = 0;
        dfs(start[0], start[1], 0);
        return dis_grid[destination[0]][destination[1]] == INT_MAX ? -1 : dis_grid[destination[0]][destination[1]];
    }
    void dfs(int r, int c, int dis) {
        for (int d = 0; d < 4; ++d) {
            int i = r, j = c, cur_dis = dis;
            while (inBound(i+dir[d][0], j+dir[d][1]) && grid[i+dir[d][0]][j+dir[d][1]] == 0) {
                ++cur_dis;
                i += dir[d][0];
                j += dir[d][1];
            }
            if (dis_grid[i][j] > cur_dis) {
                dis_grid[i][j] = cur_dis;
                dfs(i, j, cur_dis);
            }
        }
    }
    bool inBound(int r, int c) {
        return r >= 0 && r < row && c >= 0 && c < col;
    }
    vector<int> dst;
    vector<vector<int>> grid, dir, dis_grid;
    int row, col;
};