//--- Q: 0864. Shortest Path to Get All Keys

//--- method 1: bfs with recording keys for each position
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int row = grid.size(), col = grid[0].size(), tkey = 0, rstart, cstart;
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        vector<vector<vector<int>>> visit(row, vector<vector<int>>(col, vector<int>(pow(2,7)-1, 0)));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (islower(grid[i][j])) {
                    tkey |= (1 << (grid[i][j]-'a'));
                } else if (grid[i][j] == '@') {
                    rstart = i, cstart = j;
                }
            }
        }
        queue<vector<int>> que;
        que.push({0,rstart,cstart});
        visit[rstart][cstart][0] = 1;
        int dis = 0;
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                int ckey = now[0], r = now[1], c = now[2];
                if (ckey == tkey) {
                    return dis;
                }
                for (auto &dir: dirs) {
                    int nr = r+dir[0];
                    int nc = c+dir[1];
                    int nkey = ckey;
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col || grid[nr][nc] == '#') {
                        continue;
                    }
                    if (isupper(grid[nr][nc]) && !(ckey&(1<<(grid[nr][nc]-'A')))) {
                        continue;
                    }
                    if (islower(grid[nr][nc])) {
                        nkey |= (1 << (grid[nr][nc]-'a'));
                    }
                    if (!visit[nr][nc][nkey]) {
                        visit[nr][nc][nkey] = 1;
                        que.push({nkey, nr, nc});
                    }
                }
            }
            ++dis;
        }
        return -1;
    }
};

//--- method 2: dijkstra
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int row = grid.size(), col = grid[0].size(), tkey = 0, rstart, cstart;
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        vector<vector<vector<int>>> visit(row, vector<vector<int>>(col, vector<int>(pow(2,7)-1, 0)));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (islower(grid[i][j])) {
                    tkey |= (1 << (grid[i][j]-'a'));
                } else if (grid[i][j] == '@') {
                    rstart = i, cstart = j;
                }
            }
        }
        auto comp = [](const vector<int> &a, const vector<int> &b) {
            return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> que(comp);
        que.push({0,0,rstart,cstart});
        visit[rstart][cstart][0] = 1;
        while (que.size()) {
            auto now = que.top();
            que.pop();
            int dis = now[0], ckey = now[1], r = now[2], c = now[3];
            if (ckey == tkey) {
                return dis;
            }
            for (auto &dir: dirs) {
                int nr = r+dir[0];
                int nc = c+dir[1];
                int nkey = ckey;
                if (nr < 0 || nr >= row || nc < 0 || nc >= col || grid[nr][nc] == '#') {
                    continue;
                }
                if (isupper(grid[nr][nc]) && !(ckey&(1<<(grid[nr][nc]-'A')))) {
                    continue;
                }
                if (islower(grid[nr][nc])) {
                    nkey |= (1 << (grid[nr][nc]-'a'));
                }
                if (!visit[nr][nc][nkey]) {
                    visit[nr][nc][nkey] = 1;
                    que.push({dis+1, nkey, nr, nc});
                }
            }
        }
        return -1;
    }
};