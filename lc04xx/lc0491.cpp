//--- Q: 491. Increasing Subsequences

//--- method 1: dfs recursion
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> out;
        dfs(0, nums, ans, out);
        return out;
    }

    void dfs(int start, vector<int> &nums, vector<int> &ans, vector<vector<int>> &out)
    {
    	vector<int> exist(201, 0);
    	for (int i = start; i < nums.size(); ++i)
    	{
    		if (i > start && exist[nums[i]+100])
				continue;    			
    		exist[nums[i]+100] = 1;
			if (ans.size() == 0 || nums[i] >= ans.back())
			{
				ans.push_back(nums[i]);
				if (ans.size() > 1)
					out.push_back(ans);
				dfs(i+1, nums, ans, out);
				ans.pop_back();
			}
    	}
    }
};

//--- method 2: iteration
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> tmp;
        vector<vector<int>> out;
        unordered_map<int, int> exist;

        tmp.push_back({});
        for (int i = 0; i < nums.size(); ++i)
        {
            int start = exist[nums[i]];
            int n = tmp.size();
            exist[nums[i]] = n;
        	for (int j = start; j < n; ++j)
        	{
                vector<int> now = tmp[j];
                if (now.size() == 0 || now.back() <= nums[i])
                {
                    now.push_back(nums[i]);
                    if (now.size() > 1)
                        out.push_back(now);
                    tmp.push_back(now);
                }
        	}
        }
        return out;
    }
};