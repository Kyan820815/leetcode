//--- Q: 1582. Special Positions in a Binary Matrix

//--- method 1: O(1) space
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size(), res = 0;
        for (int i = 0; i < row; ++i) {
            int colsum = 0;
            for (int j = 0; j < col; ++j) {
                colsum += mat[i][j];
            }
            if (colsum == 1) {
                for (int j = 0; j < col; ++j) {
                    if (mat[i][j] == 1) {
                        int rowsum = 0;
                        for (int k = 0; k < row; ++k) {
                            rowsum += mat[k][j];
                        }
                        if (rowsum == 1) {
                            ++res;
                        }
                        break;
                    }
                }
            }
        }
        return res;
    }
};

//--- method 2: O(mn) space
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size(), res = 0;
        vector<int> rcnt(row, 0), ccnt(col, 0);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (mat[i][j]) {
                    ++rcnt[i];
                    ++ccnt[j];
                }
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (mat[i][j] && rcnt[i] == 1 && ccnt[j] == 1) {
                    ++res;
                }
            }
        }
        return res;
    }
};