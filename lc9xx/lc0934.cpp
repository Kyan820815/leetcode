//--- Q: 934. Shortest Bridge

//--- method 1: dfs+bfs
class Solution {
public:
    queue<pair<int, int>> que;
    vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int shortestBridge(vector<vector<int>>& A) {
        int row = A.size(), col = A[0].size();
        bool find = false;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (A[i][j]) {
                    dfs(i, j, A);
                    find = true;
                    break;
                }
            }
            if (find) {
                break;
            }
        }
        int res = 0;
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                for (int k = 0; k < 4; ++k) {
                    int ni = now.first + dir[k][0];
                    int nj = now.second + dir[k][1];
                    if (ni < 0 || ni >= row || nj < 0 || nj >= col) {
                        continue;
                    }
                    if (!A[ni][nj]) {
                        A[ni][nj] = -1;
                        que.push({ni, nj});
                    } else if (A[ni][nj] == 1) {
                        return res;
                    }
                }
            }
            ++res;
        }
        return -1;
    }
    void dfs(int i, int j, vector<vector<int>> &A) {
        int row = A.size(), col = A[0].size();
        A[i][j] = -1;
        bool find = false;
        for (int k = 0; k < 4; ++k) {
            int ni = i + dir[k][0];
            int nj = j + dir[k][1];
            if (ni < 0 || ni >= row || nj < 0 || nj >= col) {
                continue;
            }
            if (!A[ni][nj]) {
                find = true;
            } else if (A[ni][nj] == 1){
                dfs(ni, nj, A);
            }
        }
        if (find) {
            que.push({i, j});
        }
    }
};