//--- Q: 0283. Move Zeroes

//--- method 1: swap
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = -1;
        for (auto &num: nums) {
            if (num) {
                swap(nums[++idx], num);
            }
        }
    }
};

//--- follow up:
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = nums.size();
        for (int i = nums.size()-1; i >= 0; --i) {
            if (nums[i]) {
                swap(nums[--idx], nums[i]);
            }
        }
    }
};