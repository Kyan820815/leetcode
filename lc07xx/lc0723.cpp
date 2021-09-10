//--- Q: 0723. Candy Crush

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
                    if (i < row-2 && val == abs(board[i+1][j]) && val == abs(board[i+2][j])) {
                        find = true;
                        int idx = i;
                        while (idx < row && abs(board[idx][j]) == val) {
                            board[idx++][j] = -val;
                        }
                    }
                    if (j < col-2 && val == abs(board[i][j+1]) && val == abs(board[i][j+2])) {
                        find = true;
                        int idx = j;
                        while (idx < col && abs(board[i][idx]) == val) {
                            board[i][idx++] = -val;
                        }
                    }
                }
            }
            if (find) {
                for (int j = 0; j < col; ++j) {
                    int last = row-1;
                    for (int i = row-1; i >= 0; --i) {
                        if (board[i][j] > 0) {
                            swap(board[i][j], board[last--][j]);
                        }
                    }
                    while (last >= 0) {
                        board[last--][j] = 0;
                    }
                }
            }
        }
        return board;
    }
};