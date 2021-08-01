//--- Q: 0505. The Maze II

//--- method 1: bfs
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int row = maze.size(), col = maze[0].size();
        queue<pair<int,int>> que;
        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}}, visit(row, vector<int>(col, INT_MAX));
        que.push({start[0], start[1]});
        visit[start[0]][start[1]] = 0;
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                for (auto &dir: dirs) {
                    int nr = now.first, nc = now.second, dis = 0;
                    while (canmove(nr+dir[0], nc+dir[1], row, col) && maze[nr+dir[0]][nc+dir[1]] != 1) {
                        nr += dir[0], nc += dir[1];
                        ++dis;
                    }
                    if (visit[nr][nc] > visit[now.first][now.second]+dis) {
                        visit[nr][nc] = visit[now.first][now.second]+dis;
                        que.push({nr,nc});
                    }
                }
            }
        }
        return visit[destination[0]][destination[1]] == INT_MAX ? -1 : visit[destination[0]][destination[1]];
    }
    bool canmove(int r, int c, int row, int col) {
        return r >= 0 && r < row && c >= 0 && c < col;
    }
};

//--- method 2: Dijkstra
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int row = maze.size(), col = maze[0].size();
        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        auto comp = [](pair<int,int> &a, pair<int,int> &b) {
            return a.second > b.second;
        };
        vector<vector<int>> visit(row, vector<int>(col, INT_MAX));
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> que(comp);
        visit[start[0]][start[1]] = 0;
        que.push({start[0]*col+start[1], 0});
        while (que.size()) {
            auto now = que.top();
            que.pop();
            auto cur_dis = now.second, r = now.first/col, c = now.first%col;
            if (r == destination[0] && c == destination[1]) {
                return cur_dis;
            }
            for (auto &dir: dirs) {
                int nr = r, nc = c, dis = 0;
                while (canmove(nr+dir[0], nc+dir[1], row, col) && maze[nr+dir[0]][nc+dir[1]] != 1) {
                    nr += dir[0], nc += dir[1];
                    ++dis;
                }
                if (visit[nr][nc] > cur_dis + dis) {
                    visit[nr][nc] = cur_dis+dis;
                    que.push({nr*col+nc,cur_dis+dis});
                }
            }
        }
        return -1;
    }
    bool canmove(int r, int c, int row, int col) {
        return r >= 0 && r < row && c >= 0 && c < col;
    }
};