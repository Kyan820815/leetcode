//--- Q: 0078. Subsets

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