//--- Q: 0896. Monotonic Array

//--- method 1: count times of up and down
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int bigger = 1, smaller = 1;
        for (int i = 1; i < nums.size(); ++i) {
            bigger &= nums[i-1] >= nums[i];
            smaller &= nums[i-1] <= nums[i];
        }
        return bigger || smaller;
    }
};