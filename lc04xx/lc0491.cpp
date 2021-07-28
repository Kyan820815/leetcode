//--- Q: 0491. Increasing Subsequences

//--- method 1: dfs recursion
class Solution {
public:
    vector<int> res;
    vector<vector<int>> res_vec;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(0, nums);
        return res_vec;
    }
    void dfs(int idx, vector<int> &nums) {
        unordered_set<int> set;
        for (int i = idx; i < nums.size(); ++i) {
            if (set.find(nums[i]) != set.end()) {
                continue;
            }
            set.insert(nums[i]);
            if (!res.size() || res.back() <= nums[i]) {
                res.push_back(nums[i]);
                if (res.size() > 1) {
                    res_vec.push_back(res);
                }
                dfs(i+1, nums);
                res.pop_back();
            }
        }
    }
};

//--- method 2: iteration
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res_vec, tmp_vec = {{}};
        unordered_map<int, int> map;
        for (auto &num: nums) {
            int start = map[num], n = tmp_vec.size();
            map[num] = n;
            for (int i = start; i < n; ++i) {
                auto tmp = tmp_vec[i];
                if (!tmp.size() || tmp.back() <= num) {
                    tmp.push_back(num);
                    tmp_vec.push_back(tmp);
                    if (tmp.size() > 1) {
                        res_vec.push_back(tmp);
                    }
                }
            }
        }
        return res_vec;
    }
};