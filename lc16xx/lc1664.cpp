//--- Q: 1664. Ways to Make a Fair Array

//--- method 1: odd and even
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int rodd = 0, reven = 0, res = 0, lodd = 0, leven = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i&1) {
                rodd += nums[i];
            } else {
                reven += nums[i];
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (i&1) {
                rodd -= nums[i];
                res += lodd+reven == leven+rodd;
                lodd += nums[i];
            } else {
                reven -= nums[i];
                res += lodd+reven == leven+rodd;
                leven += nums[i];
            }
        }
        return res;
    }
};
