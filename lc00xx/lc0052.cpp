//--- Q: 0052. N-Queens II
//--- last written: 2023/06/16

//--- method 1: dfs recursion
class Solution {
public:
    vector<int> col, dig, idig;
    int res = 0;
    int totalNQueens(int n) {
        col.resize(n, 0);
        dig.resize(2*n+1, 0);
        idig.resize(2*n+1, 0);
        dfs(0, n);
        return res;
    }
    void dfs(int r, int n) {
        if (r == n) {
            ++res;
            return;
        }
        for (int c = 0; c < n; ++c) {
            if (col[c] || dig[r+c] || idig[r-c+n]) {
                continue;
            }
            col[c] = dig[r+c] = idig[r-c+n] = 1;
            dfs(r+1, n);
            col[c] = dig[r+c] = idig[r-c+n] = 0;
        }
    }
};
