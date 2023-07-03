//--- Q: 0077. Combinations
//--- last written: 2023/07/02

//--- method 1: dfs
class Solution {
public:
    vector<vector<int>> res_vec;
    vector<int> res;
    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return res_vec;
    }
    void dfs(int now, int n, int k) {
        if (!k) {
            res_vec.push_back(res);
            return;
        }
        if (n-now+1 < k) {
            return;
        }
        res.push_back(now);
        dfs(now+1, n, k-1);
        res.pop_back();
        dfs(now+1, n, k);
    }
};
