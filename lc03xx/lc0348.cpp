//--- Q: 348. Design Tic-Tac-Toe

//--- method 1: O(1) time, O(n) space
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        row_v.resize(n);
        col_v.resize(n);
        side = n;
        rd_v = ld_v = win = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int add = (player == 1) ? 1 : -1;
        row_v[row] += add;
        col_v[col] += add;
        if (row == col) {
            rd_v += add;
        }
        if (row + col == side-1) {
            ld_v += add;
        }
        if (abs(row_v[row]) == side || abs(col_v[col]) == side || abs(rd_v) == side || abs(ld_v) == side) {
            win = player;
        }
        return win;
    }
    vector<int> row_v, col_v;
    int rd_v, ld_v;
    int win, side;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */