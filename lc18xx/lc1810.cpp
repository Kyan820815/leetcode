//--- Q: 1810. Minimum Path Cost in a Hidden Grid

/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     int move(char direction);
 *     boolean isTarget();
 * };
 */

//--- method 1: dfs + dijkstra
class Solution {
public:
    vector<char> dirsc = {'U', 'L', 'D', 'R'};
    vector<pair<int,int>> dirs = {{-1,0}, {0,-1}, {1,0}, {0,1}};
    vector<vector<int>> grid, visit;
    int er = -1, ec = -1;
    int findShortestPath(GridMaster &master) {
        grid.resize(201, vector<int>(201, INT_MAX));
        visit.resize(201, vector<int>(201, INT_MAX));
        visit[100][100] = 0;
        dfs(100, 100, master);
        if (er == -1) {
            return -1;
        }
        auto comp = [](array<int,3> &a, array<int,3> &b) {
            return a[2] > b[2];
        };
        priority_queue<array<int,3>, vector<array<int,3>>, decltype(comp)> que(comp);
        que.push({100,100,0});
        while (que.size()) {
            auto now = que.top();
            que.pop();
            int r = now[0];
            int c = now[1];
            int cost = now[2];
            if (r == er && c == ec) {
                return cost;
            }
            for (auto &dir: dirs) {
                int nr = r+dir.first;
                int nc = c+dir.second;
                if (nr < 0 || nr > 200 || nc < 0 || nc >= 200 || grid[nr][nc] == -1) {
                    continue;
                }
                if (visit[nr][nc] > cost+grid[nr][nc]) {
                    visit[nr][nc] = cost+grid[nr][nc];
                    que.push({nr,nc,visit[nr][nc]});
                }
            }
        }
        return -1;
    }
    bool dfs(int r, int c, GridMaster &master) {
        if (master.isTarget()) {
            er = r, ec = c;
        }
        for (int i = 0; i < dirsc.size(); ++i) {
            int nr = r + dirs[i].first;
            int nc = c + dirs[i].second;
            if (master.canMove(dirsc[i])) {
                int cost = master.move(dirsc[i]);
                int bdir = (i+2)%4;
                if (grid[nr][nc] == INT_MAX) {
                    grid[nr][nc] = cost;
                    dfs(nr, nc, master);
                }
                master.move(dirsc[bdir]);
            } else {
                grid[nr][nc] = -1;
            }
        }
        return false;
    }
};