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
        int left = -1, right = nums.size(), maxv = INT_MIN, minv = INT_MAX;
        for (int i = 0, j = nums.size()-1; i < nums.size(); ++i, --j) {
            if (maxv > nums[i]) {
                left = i;
            } else {
                maxv = nums[i];
            }
            if (minv < nums[j]) {
                right = j;
            } else {
                minv = nums[j];
            }
        }
        return left == -1 ? 0 : left-right+1;
    }
};