//--- Q: 0565. Array Nesting

//--- method 1: one pass O(n), space O(1)
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == i) {
                continue;
            }
            int len = 1;
            while (nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
                ++len;
            }
            res = max(res, len);
        }
        return res;
    }
};