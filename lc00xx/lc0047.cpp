//--- Q: 0047. Permutations II
//--- last written: 2023/03/14

//--- method 1: dfs
class Solution {
public:
    vector<int> res, visit;
    vector<vector<int>> res_vec;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
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
            if (visit[i] || i && !visit[i-1] && nums[i] == nums[i-1]) {
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
