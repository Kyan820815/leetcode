//--- Q: 1122. Relative Sort Array

//--- method 1: counting sort
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> nums(1001,0), res;
        for (int i = 0; i < arr1.size(); ++i)
        	++nums[arr1[i]];
        for (int i = 0; i < arr2.size(); ++i)
        {
            for (int j = 0; j < nums[arr2[i]]; ++j)
        	    res.push_back(arr2[i]);
        	nums[arr2[i]] = 0;
        }
        for (int i = 0; i < 1001; ++i)
        {
        	if (nums[i])
        	{
        		for (int j = 0; j < nums[i]; ++j)
        			res.push_back(i);
        	}
        }
        return res;
    }
};