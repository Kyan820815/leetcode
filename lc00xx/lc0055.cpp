//--- Q: 0055. Jump Game
//--- last written: 2023/06/16

//--- method 1: greedy method
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxstep = nums[0], next_max_step = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            next_max_step = max(next_max_step, i+nums[i]);
            if (i > maxstep) {
                return false;
            } else if (i == maxstep) {
                maxstep = next_max_step;
            }
        }
        return true;
    }
};
