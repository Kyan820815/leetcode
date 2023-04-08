//--- Q: 0045. Jump Game II
//--- last written: 2023/03/15

//--- method 1: O(1) space, O(n) time
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        } else if (nums[0] >= nums.size()-1) {
            return 1;
        }
        int last = nums[0], maxv = 0, res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            maxv = max(maxv, i+nums[i]);
            if (i == last) {
                last = maxv;
                if (last >= nums.size()-1) {
                    return res+2;
                }
                ++res;
            }
        }
        return res;
    }
};
