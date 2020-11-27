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
                    if (i < row-2 && abs(board[i+1][j]) == val && abs(board[i+2][j]) == val) {
                        find = true;
                        int idx = i;
                        while (idx < row && abs(board[idx][j]) == val) {
                            if (board[idx][j] > 0) {
                                board[idx][j] *= -1;
                            }
                            ++idx;
                        }
                    }
                    if (j < col-2 && abs(board[i][j+1]) == val && abs(board[i][j+2]) == val) {
                        find = true;
                        int idx = j;
                        while (idx < col && abs(board[i][idx]) == val) {
                            if (board[i][idx] > 0) {
                                board[i][idx] *= -1;
                            }
                            ++idx;
                        }
                    }
                }
            }
            if (find) {
                for (int j = 0; j < col; ++j) {
                    int lastidx = row-1;
                    for (int i = row-1; i >= 0; --i) {
                        if (board[i][j] > 0) {
                            board[lastidx--][j] = board[i][j];
                        }
                    }
                    for (int i = lastidx; i >= 0; --i) {
                        board[i][j] = 0;
                    }
                }
            }
        }
        return board;
    }
};