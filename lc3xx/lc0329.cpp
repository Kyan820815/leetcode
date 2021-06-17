//--- Q: 329. Longest Increasing Path in a Matrix

//--- method 1: dfs recursion
class Solution {
public:
    int row, col;
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}}, visit;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        row = matrix.size(), col = matrix[0].size();
        visit.resize(row, vector<int>(col, -1));
        int res = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0;  j < col; ++j) {
                if (visit[i][j] == -1) {
                    dfs(i, j, matrix);
                }
                res = max(res, visit[i][j]);
            }
        }
        return res;
    }
    int dfs(int r, int c, vector<vector<int>> &matrix) {
        int dis = 0;
        if (visit[r][c] != -1) {
            return visit[r][c];
        }
        for (auto &dir: dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || matrix[r][c] <= matrix[nr][nc]) {
                continue;
            }
            dis = max(dis, dfs(nr, nc, matrix));
        }
        return visit[r][c] = dis+1;
    }
};

//--- method 2: dag + bfs
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int n = row*col, res = 0;
        vector<int> deg(n, 0);
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}}, rel(n);
        for (int i = 0; i < row; ++i) {
            for (int j = 0;  j < col; ++j) {
                for (auto &dir: dirs) {
                    int nr = i+dir[0];
                    int nc = j+dir[1];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col || matrix[i][j] >= matrix[nr][nc]) {
                        continue;
                    }
                    rel[i*col+j].push_back(nr*col+nc);
                    ++deg[nr*col+nc];
                }
            }
        }
        queue<int> que;
        for (int i = 0; i < n; ++i) {
            if (!deg[i]) {
                que.push(i);
            }
        }
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                for (auto &node: rel[now]) {
                    if (!--deg[node]) {
                        que.push(node);
                    }
                }
            }
            ++res;
        }
        return res;
    }
};