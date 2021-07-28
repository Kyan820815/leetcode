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

//--- method 2: iterative method
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res_vec = {{}};
        for (auto &num: nums) {
            vector<vector<int>> tmp_vec;
            for (auto &vec: res_vec) {
                for (int i = 0; i <= vec.size(); ++i) {
                    auto tmp = vec;
                    tmp.insert(tmp.begin()+i, num);
                    tmp_vec.push_back(tmp);
                }
            }
            res_vec = tmp_vec;
        }
        return res_vec;
    }
};