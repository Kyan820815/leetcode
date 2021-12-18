//--- Q: 2016. Maximum Difference Between Increasing Elements

//--- method 1: find minimum value
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res = INT_MIN, minv = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (minv >= nums[i]) {
                minv = nums[i];
            } else {
                res = max(res, nums[i]-minv);
            }
        }
        return res == INT_MIN ? -1 : res;
    }
};