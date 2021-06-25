//--- Q: 665. Non-decreasing Array

//--- method 1: check last, nums[i], nums[i+1], next
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int last = INT_MIN, next = INT_MAX, cnt = 1;
        for (int i = 0; i < nums.size()-1; ++i) {
            int next = (i < nums.size()-2) ? nums[i+2] : INT_MAX;
            if (nums[i] > nums[i+1] && --cnt < 0 || last > nums[i+1] && nums[i] > next) {
                return false;
            }
            last = nums[i];
        }
        return true;
    }
};