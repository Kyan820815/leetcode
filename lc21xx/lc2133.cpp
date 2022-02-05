//--- Q: 2133. Check if Every Row and Column Contains All Numbers

//--- method 1: bit set
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            bitset<101> rowset, colset;
            for (int j = 0; j < n; ++j) {
                if (rowset[matrix[i][j]]) {
                    return false;
                } else {
                    rowset[matrix[i][j]] = 1;
                }
                if (colset[matrix[j][i]]) {
                    return false;
                } else {
                    colset[matrix[j][i]] = 1;
                }
            }
        }
        return true;
    }
};

//--- method 2: O(1) space, use index
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int pos = abs(matrix[i][j])-1;
                if (matrix[i][pos] < 0) {
                    return false;
                }
                matrix[i][pos] *= -1;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int pos = abs(matrix[j][i])-1;
                if (matrix[i][pos] > 0) {
                    return false;
                }
                matrix[i][pos] *= -1;
            }
        }
        return true;
    }
};