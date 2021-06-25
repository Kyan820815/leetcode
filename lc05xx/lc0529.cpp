//--- Q: 529. Minesweeper

//--- method 1: dfs
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        row = board.size(), col = board[0].size();
        dir = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
        dfs(click[0], click[1], board);
        return board;
    }
    bool dfs(int r, int c, vector<vector<char>>& board) {
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return true;
        } else {
            int cnt = 0;
            for (int i = 0; i < 8; ++i) {
                int nr = r + dir[i][0], nc = c + dir[i][1];
                if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
                    continue;
                }
                if (board[nr][nc] == 'M') {
                    ++cnt;
                }
            }
            if (cnt > 0) {
                board[r][c] = cnt + '0';
            } else {
                board[r][c] = 'B';
                for (int i = 0; i < 8; ++i) {
                    int nr = r + dir[i][0], nc = c + dir[i][1];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
                        continue;
                    }
                    if (board[nr][nc] == 'E' && dfs(nr, nc, board)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    vector<vector<int>> dir;
    int row, col;
};

//--- method 2: bfs
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        queue<pair<int, int>> que;
        int row = board.size(), col = board[0].size();
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
        que.push({click[0], click[1]});
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                int r = now.first, c = now.second;
                if (board[r][c] == 'M') {
                    board[r][c] = 'X';
                    return board;
                } else {
                    int cnt = 0;
                    for (int i = 0; i < 8; ++i) {
                        int nr = r + dir[i][0], nc = c + dir[i][1];
                        if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
                            continue;
                        }
                        if (board[nr][nc] == 'M') {
                            ++cnt;
                        }
                    }
                    if (cnt > 0) {
                        board[r][c] = cnt + '0';
                    } else {
                        board[r][c] = 'B';
                        for (int i = 0; i < 8; ++i) {
                            int nr = r + dir[i][0], nc = c + dir[i][1];
                            if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
                                continue;
                            }
                            if (board[nr][nc] == 'E') {
                                que.push({nr, nc});
                                board[nr][nc] = 'B';
                            }
                        }
                    }
                }
            }
        }
        return board;
    }
};