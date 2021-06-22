//--- Q: 1827. Minimum Operations to Make the Array Increasing

//--- method 1:find diff between neighbor
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i-1]) {
                res += nums[i-1]+1-nums[i];
                nums[i] = nums[i-1]+1;
            }
        }
        return res;
    }
};