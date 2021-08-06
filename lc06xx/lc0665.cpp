//--- Q: 0665. Non-decreasing Array

//--- method 1: check last, nums[i], nums[i+1], next
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size(), last = INT_MIN, chance = 1;
        for (int i = 0; i < n-1; ++i) {
            int next = i+2 < n ? nums[i+2] : INT_MAX;
            if (last > nums[i+1] && nums[i] > next || nums[i] > nums[i+1] && --chance < 0) {
                return false;
            }
            last = nums[i];
        }
        return true;
    }
};