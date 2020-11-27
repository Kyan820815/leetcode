//--- Q: 078. Subsets

//--- method 1: dfs
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans_vec;
        vector<int> ans;
        int pos = 0;
        ans_vec.push_back({});
        dfs(nums, pos, ans, ans_vec);
        return ans_vec;
    }
    void dfs(vector<int> &nums, int pos, vector<int> &ans, vector<vector<int>> &ans_vec)
    {
    	for (int i = pos; i < nums.size(); ++i)
    	{
   			ans.push_back(nums[i]);
			ans_vec.push_back(ans);
			dfs(nums, i+1, ans, ans_vec);
			ans.pop_back();
		}
    }
};

//--- method 2: iterative supersposition
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans_vec(1);
        iter(nums, ans_vec);
        return ans_vec;
    }
    void iter(vector<int> &nums, vector<vector<int>> &ans_vec)
    {
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		int size = ans_vec.size();
    		for (int j = 0; j < size; ++j)
    		{
    			ans_vec.push_back(ans_vec[j]);
    			ans_vec.back().push_back(nums[i]);
    		}
    	}
    }
};