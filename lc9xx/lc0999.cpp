//--- Q: 999. Available Captures for Rook

//--- method 1: graph traverse
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size(), i, j, res = 0;
        vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        for (i = 0; i < row; ++i) {
            bool find = false;
            for (j = 0; j < col; ++j) {
                if (board[i][j] == 'R') {
                    find = true;
                    break;
                }
            }
            if (find) {
                break;
            }
        }
        for (int d = 0; d < 4; ++d) {
            for (int r = i+dir[d][0], c = j+dir[d][1]; r < row && r >= 0 && c < col && c >= 0; r += dir[d][0], c += dir[d][1]) {
                if (board[r][c] == 'p') {
                    ++res;
                }
                if (board[r][c] != '.') {
                    break;
                }
            }
        }
        return res;
    }
};