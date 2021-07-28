//--- Q: 0419. Battleships in a Board

//--- method 1: O(1) space without modifying input
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0, row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == 'X' && (i+1 == row || board[i+1][j] == '.') && (j+1 == col || board[i][j+1] == '.')) {
                    ++res;
                }
            }
        }
        return res;
    }
};