//--- Q: 35. Search Insert Position

//--- method 1: linear search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i)
        	if (nums[i] >= target) return i;
        return nums.size();
    }
};