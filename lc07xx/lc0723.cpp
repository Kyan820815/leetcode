//--- Q: 723. Candy Crush

//--- method 1: brute force, negative tag of candy
class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int row = board.size(), col = board[0].size();
        bool find = true;
        while (find) {
            find = false;
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                    if (!board[i][j]) {
                        continue;
                    }
                    int val = abs(board[i][j]);
                    if (i+2 < row && val == abs(board[i+1][j]) && val == abs(board[i+2][j])) {
                        int idx = i;
                        find = true;
                        while (idx < row && abs(board[idx][j]) == val) {
                            board[idx++][j] = -val;
                        }
                    }
                    if (j+2 < col && val == abs(board[i][j+1]) && val == abs(board[i][j+2])) {
                        int idx = j;
                        find = true;
                        while (idx < col && abs(board[i][idx]) == val) {
                            board[i][idx++] = -val;
                        }
                    }
                }
            }
            for (int c = 0; c < col; ++c) {
                int cur = row-1;
                for (int r = row-1; r >= 0; --r) {
                    if (board[r][c] > 0) {
                        swap(board[cur--][c], board[r][c]);
                    }
                }
                for (int r = cur; r >= 0; --r) {
                    board[r][c] = 0;
                }
            }
        }
        return board;
    }
};