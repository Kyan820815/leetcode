//--- Q: 417. Pacific Atlantic Water Flow

//--- method 1-1: double bfs
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if (!matrix.size()) {
            return res;
        }
        row = matrix.size(), col = matrix[0].size();
        dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        queue<pair<int, int>> pacque, atlque;
        visit.resize(row, vector<int>(col, 0));
        for (int i = 0; i < row; ++i) {
            visit[i][0] |= 1;
            visit[i][col-1] |= 2;
            pacque.push({i,0});
            atlque.push({i,col-1});
        }
        for (int i = 0; i < col; ++i) {
            visit[0][i] |= 1;
            visit[row-1][i] |= 2;
            pacque.push({0,i});
            atlque.push({row-1,i});
        }
        bfs(pacque, 1, matrix);
        bfs(atlque, 2, matrix);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (visit[i][j] == 3) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
    void bfs(queue<pair<int, int>> &que, int tag, vector<vector<int>> &matrix) {
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                for (int j = 0; j < 4; ++j) {
                    int nr = now.first + dir[j][0];
                    int nc = now.second + dir[j][1];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col || (visit[nr][nc] & tag)) {
                        continue;
                    }
                    if (matrix[nr][nc] >= matrix[now.first][now.second]) {
                        visit[nr][nc] |= tag;
                        que.push({nr, nc});
                    }
                }
            }
        }
    }
    vector<vector<int>> dir, visit;
    int row, col;
};

//--- method 1-2: revised version
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (!matrix.size()) {
            return res;
        }
        row = matrix.size(), col = matrix[0].size();
        dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        queue<pair<int, int>> pacque, atlque;
        visit.resize(row, vector<int>(col, 0));
        for (int i = 0; i < row; ++i) {
            visit[i][0] |= 1;
            visit[i][col-1] |= 2;
            pacque.push({i,0});
            atlque.push({i,col-1});
        }
        for (int i = 0; i < col; ++i) {
            if (!(visit[0][i] & 1)) {
                visit[0][i] |= 1;
                pacque.push({0, i});
            }
            if (!(visit[row-1][i] & 2)) {
                visit[row-1][i] |= 2;
                atlque.push({row-1,i});
            }
        }
        bfs(pacque, 1, matrix);
        bfs(atlque, 2, matrix);
        return res;
    }
    void bfs(queue<pair<int, int>> &que, int tag, vector<vector<int>> &matrix) {
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                if (visit[now.first][now.second] == 3 && tag == 2) {
                    res.push_back({now.first, now.second});
                }
                que.pop();
                for (int j = 0; j < 4; ++j) {
                    int nr = now.first + dir[j][0];
                    int nc = now.second + dir[j][1];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col || (visit[nr][nc] & tag)) {
                        continue;
                    }
                    if (matrix[nr][nc] >= matrix[now.first][now.second]) {
                        visit[nr][nc] |= tag;
                        que.push({nr, nc});
                    }
                }
            }
        }
    }
    vector<vector<int>> dir, visit, res;
    int row, col;
};