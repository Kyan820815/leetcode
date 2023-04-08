//--- Q: 0051. N-Queens
//--- last written: 2023/03/15

//--- method 1: dfs
class Solution {
public:
    vector<int> col, dig, idig;
    vector<vector<string>> res;
    vector<string> map;
    vector<vector<string>> solveNQueens(int n) {
        map.resize(n, string(n, '.'));
        col.resize(n, 0);
        dig.resize(2*n+1, 0);
        idig.resize(2*n+1, 0);
        dfs(0, n);
        return res;
    }
    void dfs(int r, int n) {
        if (r == n) {
            res.push_back(map);
            return;
        }
        for (int c = 0; c < n; ++c) {
            if (col[c] || dig[r+c] || idig[r-c+n]) {
                continue;
            }
            col[c] = dig[r+c] = idig[r-c+n] = 1;
            map[r][c] = 'Q';
            dfs(r+1, n);
            map[r][c] = '.';
            col[c] = dig[r+c] = idig[r-c+n] = 0;
        }
    }
};
