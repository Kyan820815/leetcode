//--- Q: 0130. Surrounded Regions

//--- method 1: dfs
class Solution {
public:
    vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int row, col;
    void solve(vector<vector<char>>& board) {
        row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i) {
            if (board[i][0] == 'O') {
                dfs(i,0,board);
            }
            if (board[i][col-1] == 'O') {
                dfs(i, col-1, board);
            }
        }
        for (int j = 0; j < col; ++j) {
            if (board[0][j] == 'O') {
                dfs(0, j, board);
            }
            if (board[row-1][j] == 'O') {
                dfs(row-1, j, board);
            }
        }
        for (int i = 0 ; i < row; ++i) {
            for (int j = 0 ; j < col; ++j) {
                if (board[i][j] == 'V') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
    void dfs(int r, int c, vector<vector<char>> &board) {
        board[r][c] = 'V';
        for (auto &dir: dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || board[nr][nc] == 'X' || board[nr][nc] == 'V') {
                continue;
            }
            dfs(nr, nc, board);
        }
    }
};