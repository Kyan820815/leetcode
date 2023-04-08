//--- Q: 0079. Word Search
//--- last written: 2023/04/05

//--- method 1: dfs without additional record array
class Solution {
public:
    int row, col;
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (dfs(i, j, 0, word, board)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(int r, int c, int idx, string &word, vector<vector<char>> &board) {
        if (board[r][c] != word[idx]) {
            return false;
        }
        if (idx == word.size()-1) {
            return true;
        }
        auto tmp = board[r][c];
        board[r][c] = 'x';
        for (auto &dir: dirs) {
            int nr = r+dir[0];
            int nc = c+dir[1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || board[nr][nc] == 'x') {
                continue;
            }
            if (dfs(nr, nc, idx+1, word, board)) {
                board[r][c] = tmp;
                return true;
            }
        }
        board[r][c] = tmp;
        return false;
    }
};
