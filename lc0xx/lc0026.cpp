//--- Q: 26. Remove Duplicates from Sorted Array

//--- method 1: partion tech of quick select
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size()) return 0;
    	int start = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
        	if (nums[i] == nums[start]) continue;
        	nums[++start] = nums[i];
        }
        return start+1;
    }
};