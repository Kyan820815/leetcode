//--- Q: 0289. Game of Life

//--- method 1: finite state machine with 4 states
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size(), col = board[0].size();
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int live = 0;
                for (auto &dir: dirs) {
                    int nr = i+dir[0];
                    int nc = j+dir[1];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col || !(board[nr][nc]&1)) {
                        continue;
                    }
                    ++live;
                }
                if (board[i][j] && (live == 2 || live == 3)) {
                    board[i][j] |= 2;
                } else if (!board[i][j] && live == 3) {
                    board[i][j] |= 2;
                }
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};