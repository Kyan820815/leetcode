//--- Q: 0216. Combination Sum III

//--- method 1: dfs recursion
class Solution {
public:
    vector<int> res;
    vector<vector<int>> res_vec;
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n);
        return res_vec;
    }
    void dfs(int idx, int k, int n) {
        if (n <= 0) {
            if (!n && !k) {
                res_vec.push_back(res);
            }
            return;
        }
        if (9-idx+1 < k) {
            return;
        }
        for (int i = idx; i < 10; ++i) {
            res.push_back(i);
            dfs(i+1, k-1, n-i);
            res.pop_back();
        }
    }
};