//--- Q: 0329. Longest Increasing Path in a Matrix

//--- method 1: dfs recursion
class Solution {
public:
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<vector<int>> visit;
    int row, col;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        row = matrix.size(), col = matrix[0].size();
        int res = 0;
        visit.resize(row, vector<int>(col, -1));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (visit[i][j] == -1) {
                    dfs(i, j, matrix);
                }
                res = max(res, visit[i][j]);
            }
        }
        return res;
    }
    int dfs(int r, int c, vector<vector<int>> &matrix) {
        if (visit[r][c] != -1) {
            return visit[r][c];
        }
        int maxv = 0;
        for (auto &dir: dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || matrix[r][c] >= matrix[nr][nc]) {
                continue;
            }
            maxv = max(maxv, dfs(nr, nc, matrix));
        }
        return visit[r][c] = maxv+1;
    }
};

//--- method 2: dag + bfs
class Solution {
public:
    vector<vector<int>> visit;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size(), res = 0;
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}}, rel(row*col);
        vector<int> deg(row*col, 0);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int idx = i*col+j;
                for (auto &dir: dirs) {
                    int nr = i + dir[0];
                    int nc = j + dir[1];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col || matrix[i][j] >= matrix[nr][nc]) {
                        continue;
                    }
                    int nidx = nr*col+nc;
                    rel[idx].push_back(nidx);
                    ++deg[nidx];
                }
            }
        }
        queue<int> que;
        for (int i = 0; i < deg.size(); ++i) {
            if (!deg[i]) {
                que.push(i);
            }
        }
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                for (auto &next: rel[now]) {
                    if (!--deg[next]) {
                        que.push(next);
                    }
                }
            }
            ++res;
        }
        return res;
    }
};