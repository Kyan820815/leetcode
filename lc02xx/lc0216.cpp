//--- Q: 216. Combination Sum III

//--- method 1: dfs recursion
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
    	vector<vector<int>> res_vec;
    	vector<int> res;
    	dfs(1, k, n, res, res_vec);
    	return res_vec;
    }
    void dfs(int start_idx, int k, int target, vector<int> &res, vector<vector<int>> &res_vec)
    {
    	if (k == 0 && target == 0)
    	{
    		res_vec.push_back(res);
    		return;
    	}
    	for (int i = start_idx; i <= 9; ++i)
    	{
    		res.push_back(i);
    		dfs(i+1, k-1, target-i, res, res_vec);
    		res.pop_back();
    	}
    }
};