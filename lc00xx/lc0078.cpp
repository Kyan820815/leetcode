//--- Q: 0078. Subsets
//--- last written: 2023/07/02

//--- method 1: dfs
class Solution {
public:
    vector<vector<int>> res_vec = {{}};
    vector<int> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return res_vec;
    }
    void dfs(int idx, vector<int> &nums) {
        for (int i = idx; i < nums.size(); ++i) {
            res.push_back(nums[i]);
            res_vec.push_back(res);
            dfs(i+1, nums);
            res.pop_back();
        }
    }
};

//--- method 2: iteration
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res_vec = {{}};
        for (auto &num: nums) {
            int sz = res_vec.size();
            for (int i = 0; i < sz; ++i) {
                auto vec = res_vec[i];
                vec.push_back(num);
                res_vec.push_back(vec);
            }
        }
        return res_vec;
    }
};
