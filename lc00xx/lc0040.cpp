//--- Q: 40. Combination Sum II

//--- method 1: recursion
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> res;
        vector<vector<int>> res_vec;
        sort(candidates.begin(), candidates.end());
        dfs(0, target, candidates, res, res_vec);
        return res_vec;
    }
    void dfs(int start_idx, int target, vector<int> &candidates, vector<int> &res, vector<vector<int>> &res_vec)
    {
    	if (target < 0) return;
    	if (target == 0)
    		res_vec.push_back(res);

    	for (int i = start_idx; i < candidates.size(); ++i)
    	{
            if (i > start_idx && candidates[i] == candidates[i-1])
                continue;
    		res.push_back(candidates[i]);
    		dfs(i+1, target-candidates[i], candidates, res, res_vec);
	    	res.pop_back();
    	}
    }
};