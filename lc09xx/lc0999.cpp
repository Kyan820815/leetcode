//--- Q: 0999. Available Captures for Rook

//--- method 1: graph traverse
class Solution {
public:
    int row, col;
    int numRookCaptures(vector<vector<char>>& board) {
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int res = 0;
        row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == 'R') {
                    for (auto &dir: dirs) {
                        int r = i, c = j;
                        while (valid(r+dir[0],c+dir[1])) {
                            r += dir[0], c += dir[1];
                            if (board[r][c] == 'p') {
                                ++res;
                            } else if (board[r][c] == '.') {
                                continue;
                            }
                            break;
                        }
                    }
                    return res;
                }
            }
        }
        return -1;
    }
    bool valid(int r, int c) {
        return r >= 0 && r < row && c >= 0 && c < col;
    }
};