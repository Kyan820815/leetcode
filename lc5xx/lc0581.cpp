//--- Q: 581. Shortest Unsorted Continuous Subarray

//--- method 1: swap nums[i] to it correct position
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
    	int start = -1, res = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
        	if (nums[i] > nums[i-1])
        	{
        		int j = i;
        		while (j > 0 && nums[j] < nums[j-1])
        		{
        			swap(nums[j], nums[j-1]);
        			--j;
        		}
        		if (start == -1 || start > j)
        			start = j;
        		res = i-start+1;
        	}
        }
        return res;
    }
};

//--- method 2: sort
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
    	vector<int> t = nums;
    	sort(t.begin(), t.end());
    	int i = 0, j = nums.size()-1;
    	while (i < nums.size() && nums[i] == t[i]) ++i;
    	while (j > i && nums[j] == t[j]) --j;
    	return j-i+1;
    }
};

//--- method 3: O(n), better
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
    	int left = 0, right = nums.size()-1, minv = INT_MAX, maxv = INT_MIN;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		maxv = max(maxv, nums[i]);
    		if (maxv > nums[i]) right = i;
    	}
    	for (int i = nums.size()-1; i >= 0; --i)
    	{
    		minv = min(minv, nums[i]);
    		if (minv < nums[i]) left = i;
    	}
    	return (left == 0 && right == nums.size()-1) ? 0 : right-left+1;
    }
};