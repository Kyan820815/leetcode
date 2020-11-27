//--- Q: 1252. Cells with Odd Values in a Matrix

//--- method 1: O(m*n + l)
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> rows(n, 0), cols(m, 0);
        int res = 0;
        for (int i = 0; i < indices.size(); ++i) {
            ++rows[indices[i][0]];
            ++cols[indices[i][1]];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((rows[i] + cols[j])&1) {
                    ++res;
                }
            }
        }
        return res;
    }
};

//--- method 1-2: use xor instead of adding
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> rows(n, 0), cols(m, 0);
        int res = 0;
        for (int i = 0; i < indices.size(); ++i) {
            rows[indices[i][0]] ^= 1;
            cols[indices[i][1]] ^= 1;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((rows[i] ^ cols[j]) == 1) {
                    ++res;
                }
            }
        }
        return res;
    }
};

//--- method 2: O(m+n+l), better
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> rows(n, 0), cols(m, 0);
        int cntr = 0, cntc = 0;
        for (int i = 0; i < indices.size(); ++i) {
            rows[indices[i][0]] ^= 1;
            cols[indices[i][1]] ^= 1;
        }
        for (int i = 0; i < n; ++i) {
            cntr += rows[i] == 1;
        }
        for (int j = 0; j < m; ++j) {
            cntc += cols[j] == 1;
        }
        return (n-cntr) * cntc + (m-cntc) * cntr;
    }
};
