//--- Q: 1926. Nearest Exit from Entrance in Maze

//--- method 1: bfs
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int row = maze.size(), col = maze[0].size(), res = 0;
        queue<array<int,2>> que;
        que.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                for (auto &dir: dirs) {
                    int nr = now[0]+dir[0];
                    int nc = now[1]+dir[1];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
                        if (res) {
                            return res;
                        }
                    } else if (maze[nr][nc] == '.') {
                        maze[nr][nc] = '+';
                        que.push({nr,nc});
                    }
                }
            }
            ++res;
        }
        return -1;
    }
};
