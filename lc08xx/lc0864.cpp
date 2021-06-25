//--- Q: 864. Shortest Path to Get All Keys

//--- method 1: bfs with recording keys for each position
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int res = 0, row = grid.size(), col = grid[0].size();
        int sr, sc, key = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '@') {
                    sr = i, sc = j;
                } else if (islower(grid[i][j])) {
                    key |= (1 << (grid[i][j]-'a'));
                }
            }
        }
        queue<vector<int>> que;
        que.push({sr, sc, 0});
        unordered_set<string> set;
        set.insert(to_string(sr) + "_" + to_string(sc) + "_" + to_string(0));
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                for (int j = 0; j < 4; ++j) {
                    int nr = now[0] + dir[j][0];
                    int nc = now[1] + dir[j][1];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col || grid[nr][nc] == '#') {
                        continue;
                    }
                    if (isupper(grid[nr][nc]) && ((1 << (tolower(grid[nr][nc])-'a')) & now[2]) == 0) {
                        continue;
                    }
                    int nextkey = now[2];
                    if (islower(grid[nr][nc])) {
                        nextkey |= (1 << (grid[nr][nc]-'a'));
                    }
                    string tag = to_string(nr) + "_" + to_string(nc) + "_" + to_string(nextkey);
                    if (nextkey == key) {
                        return res+1;
                    }
                    if (set.find(tag) == set.end()) {
                        set.insert(tag);
                        que.push({nr, nc, nextkey});
                    }
                }
            }
            ++res;
        }
        return -1;
    }
};