//--- Q: 0036. Valid Sudoku
//--- last written: 2022/11/18

//--- method 1: hashmap, clean code
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size();
        unordered_set<string> set;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                string rtag = "r"+to_string(i)+board[i][j];
                string ctag = "c"+to_string(j)+board[i][j];
                string btag = "b"+to_string((i/3)*3+j/3)+board[i][j];
                if (set.find(rtag) != set.end() || set.find(ctag) != set.end() || set.find(btag) != set.end()) {
                    return false;
                }
                set.insert(rtag);
                set.insert(ctag);
                set.insert(btag);
            }
        }
        return true;
    }
};

//--- method 2: 2d vector
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(9)), col(9, vector<int>(9)), block(9, vector<int>(9));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                int idx = board[i][j]-'0'-1;
                int blockid = (i/3)*3+j/3;
                if (++row[i][idx] > 1 || ++col[j][idx] > 1 || ++block[blockid][idx] > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};
