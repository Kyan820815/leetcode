//--- Q: 442. Find All Duplicates in an Array

//--- method 1: negative checking
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[abs(nums[i])-1] < 0)
				res.push_back(abs(nums[i]));
			nums[abs(nums[i])-1] *= -1;
		}
		return res;      
    }
};

//--- method 2: swapping method
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
    	vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
        {
        	if (nums[i] != nums[nums[i]-1])
        	{
        		swap(nums[i], nums[nums[i]-1]);
        		--i;
        	}
        }
        for (int i = 0; i < nums.size(); ++i)
        {
        	if (nums[i] != i+1)
        		res.push_back(nums[i]);
        }
        return res;
    }
};

//--- method 3: 2*n times checking
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < nums.size(); ++i)
        {
        	nums[(nums[i]-1)%n] += n;
        }
        for (int i = 0; i < n; ++i)
        {
        	if (nums[i] > 2*n)
        		res.push_back(i+1);
        }
        return res;
    }
};