//--- Q: 0213. House Robber II

//--- method 1: 2 times pass
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int odd = 0, even = 0, n = nums.size();
        for (int i = 0; i < n-1; ++i) {
            if (i&1) {
                odd = max(odd+nums[i], even);
            } else {
                even = max(even+nums[i], odd);
            }
        }
        int res = max(odd, even);
        odd = even = 0;
        for (int i = 1; i < n; ++i) {
            if (i&1) {
                odd = max(odd+nums[i], even);
            } else {
                even = max(even+nums[i], odd);
            }
        }
        return max(res, max(odd, even));
    }
};