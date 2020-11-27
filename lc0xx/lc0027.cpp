//--- Q: 27. Remove Element

//--- method 1: partition tech of quick select
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    	int start = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
        	if (nums[i] != val)
        		nums[++start] = nums[i];
        }
        return start+1;
    }
};