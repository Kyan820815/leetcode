//--- Q: 047. Permutations II

//--- method 1: dfs
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> out, visit(nums.size(), 0);
        vector<vector<int>> out_vec;
        sort(nums.begin(), nums.end());
        dfs(nums, visit, out, out_vec);
        return out_vec;
    }
    void dfs(vector<int> &nums, vector<int> &visit, vector<int> &out, vector<vector<int>> &out_vec)
    {
    	bool finish = true;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		if (i > 0 && nums[i] == nums[i-1] && !visit[i-1]) continue;
    		if (!visit[i])
    		{
    			finish = false;
	    		out.push_back(nums[i]);
	    		visit[i] = 1;
	    		dfs(nums, visit, out, out_vec);
	    		visit[i] = 0;
	    		out.pop_back();
    		}
    	}
    	if (finish)
    		out_vec.push_back(out);
    }
};