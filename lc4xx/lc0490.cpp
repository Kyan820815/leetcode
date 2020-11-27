//---  Q: 490. The Maze

//--- method 1: dfs
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int row = maze.size(), col = maze[0].size();
        dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        dst = destination, grid = maze;
        return dfs(start[0], start[1], row, col);
    }
    bool dfs(int r, int c, int row, int col) {
        grid[r][c] = 2;
        for (int i = 0; i < 4; ++i) {
            int x = r, y = c;
            int nr = r + dirs[i][0], nc = c + dirs[i][1];
            while (nr < row && nr >= 0 && nc < col && nc >= 0 && (grid[nr][nc] == 0 || grid[nr][nc] == 2)) {
                x = nr;
                y = nc;
                nr = x + dirs[i][0], nc = y + dirs[i][1];
            }
            if (x == dst[0] && y == dst[1]) {
                return true;
            }
            if (grid[x][y] != 2 && dfs(x, y, row, col)) {
                return true;
            }
        }
        return false;
    }
    vector<vector<int>> grid, dirs;
    vector<int> dst;
    
};

//--- method 2: bfs
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<pair<int, int>> que;
        vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int row = maze.size(), col = maze[0].size();
        que.push({start[0], start[1]});
        maze[start[0]][start[1]] = 2;
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                for (int j = 0; j < 4; ++j) {
                    int nowr = now.first, nowc = now.second;
                    while (canMove(nowr+dir[j][0], nowc+dir[j][1], row, col) && maze[nowr+dir[j][0]][nowc+dir[j][1]] != 1) {
                        nowr += dir[j][0];
                        nowc += dir[j][1];
                    }
                    if (nowr == destination[0] && nowc == destination[1]) {
                        return true;
                    } else if (maze[nowr][nowc] != 2) {
                        que.push({nowr, nowc});
                        maze[nowr][nowc] = 2;
                    }
                }
            }
        }
        return false;
    }
    bool canMove(int r, int c, int row, int col) {
        return r >= 0 && r < row && c >= 0 && c < col;
    }
};