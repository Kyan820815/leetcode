//--- Q: 0040. Combination Sum II
//--- last written: 2022/11/06

//--- method 1: recursion
class Solution {
public:
    vector<int> res;
    vector<vector<int>> res_vec;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, target, candidates);
        return res_vec;
    }
    void dfs(int idx, int target, vector<int> &candidates) {
        if (target <= 0) {
            if (!target) {
                res_vec.push_back(res);
            }
            return;
        }
        for (int i = idx; i < candidates.size(); ++i) {
            if (i > idx && candidates[i] == candidates[i-1]) {
                continue;
            }
            res.push_back(candidates[i]);
            dfs(i+1, target-candidates[i], candidates);
            res.pop_back();
        }
    }
};
