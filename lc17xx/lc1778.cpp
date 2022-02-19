//--- Q: 1778. Shortest Path in a Hidden Grid

/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     void move(char direction);
 *     boolean isTarget();
 * };
 */

//--- method 1: dfs+bfs
class Solution {
public:
    vector<char> dirsc = {'U', 'L', 'D', 'R'};
    vector<pair<int,int>> dirs = {{-1,0}, {0,-1}, {1,0}, {0,1}};
    vector<vector<int>> grid;
    int er = -1, ec;
    int findShortestPath(GridMaster &master) {
        grid.resize(1001, vector<int>(1001, INT_MAX));
        grid[500][500] = 0;
        dfs(500, 500, master);
        if (er == -1) {
            return -1;
        }
        queue<array<int,2>> que;
        que.push({500,500});
        int dis = 0;
        while (que.size()) {
            int qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                int r = now[0], c = now[1];
                if (r == er && c == ec) {
                    return dis;
                }
                for (auto &dir: dirs) {
                    int nr = r+dir.first;
                    int nc = c+dir.second;
                    if (nr < 0 || nr > 1000 || nc < 0 || nc > 1000 || (grid[nr][nc] != 0 && grid[nr][nc] != 2)) {
                        continue;
                    }
                    grid[nr][nc] = 1;
                    que.push({nr,nc});
                }
            }
            ++dis;
        }
        return -1;
    }
    void dfs(int r, int c, GridMaster &master) {
        if (master.isTarget()) {
            grid[r][c] = 2;
            er = r, ec = c;
        }
        for (int i = 0; i < 4; ++i) {
            int nr = r+dirs[i].first;
            int nc = c+dirs[i].second;
            if (master.canMove(dirsc[i])) {
                if (grid[nr][nc] == INT_MAX) {
                    grid[nr][nc] = 0;
                    master.move(dirsc[i]);
                    dfs(nr, nc, master);
                    master.move(dirsc[(i+2)%4]);
                }
            } else {
                grid[nr][nc] = 1;
            }
        }
    }
};