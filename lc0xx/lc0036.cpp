//--- Q: 36. Valid Sudoku

//--- method 1: hashmap, clean code
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> set;
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                string rtag = "r_" + to_string(i) + "_" + board[i][j];
                string ctag = "c_" + to_string(j) + "_" + board[i][j];
                string btag = "b_" + to_string((i/3)*3+j/3) + "_" + board[i][j];
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

//--- method 2: hashmap
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> map;
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row-2; i+=3) {
            for (int j = 0; j < col-2; j+=3) {
                unordered_set<int> grid;
                for (int k = i; k < i+3; ++k) {
                    for (int l = j; l < j+3; ++l) {
                        if (board[k][l] == '.') {
                            continue;
                        }
                        if (map[k].find(board[k][l]) != map[k].end() 
                            || map[row+l].find(board[k][l]) != map[row+l].end()
                            || grid.find(board[k][l]) != grid.end()) {
                            return false;
                        }
                        grid.insert(board[k][l]);
                        map[k].insert(board[k][l]);
                        map[row+l].insert(board[k][l]);
                    }
                }
            }
        }
        return true;
    }
};