//--- Q: 0485. Max Consecutive Ones

//--- method 1: one pass
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int last = -1, res = 0;
        for (int i = 0; i <= nums.size(); ++i) {
            if (i == nums.size() || !nums[i]) {
                res = max(res, i-last-1);
                last = i;
            }
        }
        return res;
    }
};