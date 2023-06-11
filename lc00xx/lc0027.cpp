//--- Q: 0027. Remove Element
//--- last written: 2023/06/05

//--- method 1: partition tech of quick select
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx = -1;
        for (auto &num: nums) {
            if (num != val) {
                swap(nums[++idx], num);
            }
        }
        return idx+1;
    }
};
