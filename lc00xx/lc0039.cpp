//--- Q: 39. Combination Sum

//--- method 1: recursion
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> res;
        vector<vector<int>> res_vec;
        dfs(0, target, candidates, res, res_vec);
        return res_vec;
    }
    void dfs(int start_idx, int target, vector<int> &candidates, vector<int> &res, vector<vector<int>> &res_vec)
    {
    	if (start_idx == candidates.size() || target <= 0)
    	{
    		if (!target)
    			res_vec.push_back(res);
            return;
    	}
    	dfs(start_idx+1, target, candidates, res, res_vec);
    	res.push_back(candidates[start_idx]);
    	dfs(start_idx, target-candidates[start_idx], candidates, res, res_vec);
    	res.pop_back();
    }
};