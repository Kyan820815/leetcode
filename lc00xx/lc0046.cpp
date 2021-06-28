//--- Q: 0046. Permutations

//--- method 1: dfs with process recorder "visit", better(faster)
class Solution {
public:
    vector<int> res, visit;
    vector<vector<int>> res_vec;
    vector<vector<int>> permute(vector<int>& nums) {
        visit.resize(nums.size(), 0);
        dfs(nums);
        return res_vec;
    }
    void dfs(vector<int> &nums) {
        if (res.size() == nums.size()) {
            res_vec.push_back(res);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (visit[i]) {
                continue;
            }
            visit[i] = 1;
            res.push_back(nums[i]);
            dfs(nums);
            visit[i] = 0;
            res.pop_back();
        }
    }
};