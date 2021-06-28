//--- Q: 0039. Combination Sum

//--- method 1: recursion
class Solution {
public:
    vector<int> res;
    vector<vector<int>> res_vec;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
            res.push_back(candidates[i]);
            dfs(i, target-candidates[i], candidates);
            res.pop_back();
        }
    }
};