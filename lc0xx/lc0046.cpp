//--- Q: 046. Permutations

//--- method 1: dfs with process recorder "visit", better(faster)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> out, visit(nums.size(), 0);
        vector<vector<int>> out_vec;
        dfs(nums, visit, out, out_vec);
        return out_vec;
    }
    void dfs(vector<int> &nums, vector<int> &visit, vector<int> &out, vector<vector<int>> &out_vec)
    {
    	bool finish = true;
    	for (int i = 0; i < nums.size(); ++i)
    	{
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

//--- method 2: swap 
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> out;
        vector<vector<int>> out_vec;
        dfs(nums, 0, out_vec);
        return out_vec;
    }
    void dfs(vector<int> &nums, int start, vector<vector<int>> &out_vec)
    {
    	if (start == nums.size())
    		out_vec.push_back(nums);
    	for (int i = start; i < nums.size(); ++i)
    	{
    		swap(nums[start], nums[i]);
    		dfs(nums, start+1, out_vec);
    		swap(nums[start], nums[i]);
    	}
    }
};

//--- method 3: dfs with erase and insert
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> out;
        vector<vector<int>> out_vec;
        dfs(nums, out, out_vec);
        return out_vec;
    }
    void dfs(vector<int> &nums, vector<int> &out, vector<vector<int>> &out_vec)
    {
    	if (nums.size() == 0)
    		out_vec.push_back(out);
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		out.push_back(nums[i]);
    		nums.erase(nums.begin()+i);
    		dfs(nums, out, out_vec);
    		nums.insert(nums.begin()+i, out.back());
    		out.pop_back();
    	}
    }
};

//--- method 4: iterative solution
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> out;
        vector<vector<int>> out_vec;

        out_vec.push_back({nums[0]});
        for (int i = 1; i < nums.size(); ++i)
        {
        	int size = out_vec.size();
        	for (int j = 0; j < size; ++j)
        	{
        		out = out_vec.front();
	        	out_vec.erase(out_vec.begin());
	        	for (int k = 0; k <= out.size(); ++k)
	        	{
	 				vector<int> t = out;
	 				t.insert(t.begin()+k, nums[i]);
	 				out_vec.push_back(t);
	        	}
        	}
        }
        return out_vec;
    }
};