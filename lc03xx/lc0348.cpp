//--- Q: 0348. Design Tic-Tac-Toe

//--- method 1: O(1) time, O(n) space
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rcnt.resize(n, 0);
        ccnt.resize(n, 0);
        dig = idig = 0, cnt = n;
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
        int val = player == 1 ? 1 : -1;
        rcnt[row] += val;
        ccnt[col] += val;
        dig += row == col ? val : 0;
        idig += row+col == cnt-1 ? val : 0;
        if (abs(rcnt[row]) == cnt || abs(ccnt[col]) == cnt || abs(dig) == cnt || abs(idig) == cnt) {
            return player;
        }
        return 0;
    }
    vector<int> rcnt, ccnt;
    int dig, idig, cnt;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */