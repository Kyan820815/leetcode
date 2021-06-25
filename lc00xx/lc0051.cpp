//--- Q: 051. N-Queens

//--- method 1: dfs
class Solution {
public:
    vector<string> res;
    vector<vector<string>> res_vec;
    vector<vector<string>> solveNQueens(int n) {
        res.resize(n, string(n, '.'));
        vector<int> ccnt(n, 0), dig(n*2+1, 0), idig(n*2+1, 0);
        dfs(0, n, ccnt, dig, idig);
        return res_vec;
    }
    void dfs(int r, int n, vector<int> &ccnt, vector<int> &dig, vector<int> &idig) {
        if (r == n) {
            res_vec.push_back(res);
            return;
        }
        for (int c = 0; c < n; ++c) {
            if (!ccnt[c] && !dig[r-c+n] && !idig[r+c]) {
                ccnt[c] = dig[r-c+n] = idig[r+c]= 1;
                res[r][c] = 'Q';
                dfs(r+1, n, ccnt, dig, idig);
                res[r][c] = '.';
                ccnt[c] = dig[r-c+n] = idig[r+c]= 0;
            }
        }
    }
};