//--- Q: 665. Non-decreasing Array

//--- method 1: check last, nums[i], nums[i+1], next
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int credit = 1, last = -100001;
        for (int i = 0; i < nums.size()-1; ++i) {
            if (nums[i] > nums[i+1]) {
                int next = (i+2 == nums.size()) ? 100001 : nums[i+2];
                if (--credit < 0 || last > nums[i+1] && nums[i] > next) {
                    return false;
                }
            }
            last = nums[i];
        }
        return true;
    }
};