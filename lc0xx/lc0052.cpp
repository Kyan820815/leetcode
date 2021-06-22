//--- Q: 0052. N-Queens II

//--- method 1: dfs recursion
class Solution {
public:
    int res = 0;
    int totalNQueens(int n) {
        vector<int> col(n, 0), dig(2*n+1, 0), idig(2*n+1, 0);
        dfs(0, n, col, dig, idig);
        return res;
    }
    void dfs(int r, int n, vector<int> &col, vector<int> &dig, vector<int> &idig) {
        if (r == n) {
            ++res;
            return;
        }
        for (int c = 0; c < n; ++c) {
            if (!col[c] && !dig[r-c+n] && !idig[r+c]) {
                col[c] = dig[r-c+n] = idig[r+c] = 1;
                dfs(r+1, n, col, dig, idig);
                col[c] = dig[r-c+n] = idig[r+c] = 0;
            }
        }
    }
};