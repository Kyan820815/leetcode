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

//--- method 2: iteration
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res_vec = {{}};
        sort(nums.begin(), nums.end());
        int last = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int start = i && nums[i] == nums[i-1] ? last : 0;
            last = res_vec.size();
            for (int j = start; j < last; ++j) {
                auto tmp = res_vec[j];
                tmp.push_back(nums[i]);
                res_vec.push_back(tmp);
            }
        }
        return res_vec;
    }
};