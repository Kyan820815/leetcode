//--- Q: 090. Subsets II

//--- method 1: iteration with non-repeated check, better
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans_vec(1);
        vector<int> ans;
        sort(nums.begin(), nums.end());
        iter(nums, ans_vec);
        return ans_vec;
    }
    void iter(vector<int> &nums, vector<vector<int>> &ans_vec)
    {
        int last_size, size=0, start;
        for (int i = 0; i < nums.size(); ++i)
        {
            last_size = size;
            size = ans_vec.size();
            start = (i>0 && nums[i]==nums[i-1]) ? last_size : 0;
            for (int j = start; j < size; ++j)
            {
                ans_vec.push_back(ans_vec[j]);
                ans_vec.back().push_back(nums[i]);
            }
        }
    }
};

//--- method 2: dfs with remove duplicate vector (elegant version), better
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans_vec;
        vector<int> ans;
        int pos = 0;
        ans_vec.push_back({});
        sort(nums.begin(), nums.end());
        dfs(nums, pos, ans, ans_vec);
        return ans_vec;
    }
    void dfs(vector<int> &nums, int pos, vector<int> &ans, vector<vector<int>> &ans_vec)
    {
        for (int i = pos; i < nums.size(); ++i)
        {
            if (i>pos && nums[i] == nums[i-1]) continue;
            ans.push_back(nums[i]);
            ans_vec.push_back(ans);
            dfs(nums, i+1, ans, ans_vec);
            ans.pop_back();
        }
    }
};

//--- method 3:  dfs with remove duplicate vector
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans_vec;
        vector<int> ans;
        int pos = 0;
        ans_vec.push_back({});
        sort(nums.begin(), nums.end());
        dfs(nums, pos, ans, ans_vec);
        return ans_vec;
    }
    void dfs(vector<int> &nums, int pos, vector<int> &ans, vector<vector<int>> &ans_vec)
    {
    	for (int i = pos; i < nums.size(); ++i)
    	{
   			ans.push_back(nums[i]);
   			if (find(ans_vec.begin(), ans_vec.end(), ans) == ans_vec.end())
				ans_vec.push_back(ans);
			dfs(nums, i+1, ans, ans_vec);
			ans.pop_back();
		}
    }
};