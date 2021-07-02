//--- Q: 0090. Subsets II

//--- method 1: dfs recursion
class Solution {
public:
    vector<vector<int>> res_vec = {{}};
    vector<int> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        return res_vec;
    }
    void dfs(int idx, vector<int> &nums) {
        for (int i = idx; i < nums.size(); ++i) {
            if (i > idx && nums[i] == nums[i-1]) {
                continue;
            }
            res.push_back(nums[i]);
            res_vec.push_back(res);
            dfs(i+1, nums);
            res.pop_back();
        }
    }
};