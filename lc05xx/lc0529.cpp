//--- Q: 0529. Minesweeper

//--- method 2: bfs
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};
        int row = board.size(), col = board[0].size();
        queue<pair<int,int>> que;
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        que.push({click[0], click[1]});
        board[click[0]][click[1]] = 'B';
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                int cnt = 0;
                for (auto &dir: dirs) {
                    int nr = now.first + dir[0];
                    int nc = now.second + dir[1];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
                        continue;
                    }
                    if (board[nr][nc] == 'M') {
                        ++cnt;                        
                    }
                }
                if (!cnt) {
                    for (auto &dir: dirs) {
                        int nr = now.first + dir[0];
                        int nc = now.second + dir[1];
                        if (nr < 0 || nr >= row || nc < 0 || nc >= col || board[nr][nc] != 'E') {
                            continue;
                        }
                        board[nr][nc] = 'B';
                        que.push({nr,nc});
                    }
                } else {
                    board[now.first][now.second] = cnt+'0';
                }
            }
        }
        return board;
    }
};