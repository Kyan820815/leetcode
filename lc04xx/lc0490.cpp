//--- Q: 0490. The Maze

//--- method 1: bfs
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int row = maze.size(), col = maze[0].size();
        queue<pair<int,int>> que;
        que.push({start[0], start[1]});
        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                for (auto &dir: dirs) {
                    auto r = now.first, c = now.second;
                    while (canmove(r+dir[0], c+dir[1], row, col) && maze[r+dir[0]][c+dir[1]] != 1) {
                        r += dir[0], c += dir[1];
                    }
                    if (maze[r][c] == 2) {
                        continue;
                    }
                    maze[r][c] = 2;
                    que.push({r,c});
                }
            }
        }
        return maze[destination[0]][destination[1]] == 2;
    }
    bool canmove(int r, int c, int row, int col) {
        return r >= 0 && r < row && c >= 0 && c < col;
    }
};