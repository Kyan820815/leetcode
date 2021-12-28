//--- Q: 0905. Sort Array By Parity

//--- method 1: odd even change, partition of quick select
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int idx = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (!(nums[i]&1)) {
                swap(nums[++idx], nums[i]);
            }
        }
        return nums;
    }
};