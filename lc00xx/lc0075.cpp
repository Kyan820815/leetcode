//--- Q: 0075. Sort Colors
//--- last written: 2023/07/04

//--- method 1-1: two pointer
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = -1, twos = nums.size();
        for (int i = 0; i < nums.size();) {
            if (nums[i] == 1) {
                ++i;
                continue;
            } else if (!nums[i]) {
                swap(nums[++zeros], nums[i++]);
            } else if (i < twos) {
                swap(nums[--twos], nums[i]);
            } else {
                break;
            }
        }
    }
};
