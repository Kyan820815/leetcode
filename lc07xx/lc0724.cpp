//--- Q: 0724. Find Pivot Index

//--- method 1: comparison between left_sum and right_sum
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (auto &num: nums) {
            sum += num;
        }
        int left = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (left*2 == sum-nums[i]) {
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};