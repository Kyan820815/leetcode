//--- Q: 645. Set Mismatch

//--- method 1: sum method
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    	vector<int> res(nums.size()+1, 0);
        int n = nums.size(), sum = (1+n)*n/2;
        int dup, val = 0;
        for (int i = 0; i < n; ++i)
        {
        	val += nums[i];
        	if (!res[nums[i]])
        		dup = nums[i];
        	++res[nums[i]];
        }
        return {dup, sum-(val-dup)};
    }
};

//--- method 2: turn to negative iwhen pointed to that index
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    	vector<int> res(2,-1);
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		if (nums[abs(nums[i])-1] < 0)
    			res[0] = abs(nums[i]);
    		else
    			nums[abs(nums[i])-1] *= -1;
    	}
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		if (nums[i] > 0)
    		{
    			res[1] = i+1;
    			break;
    		}
    	}
    	return res;
    }
};