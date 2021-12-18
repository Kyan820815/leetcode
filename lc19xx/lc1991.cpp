//--- Q: 1911. Find the Middle Index in Array

//--- method 1: prefix sum
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int left = 0, right = 0;
        for (auto &num: nums) {
            right += num;
        }
        for (int i = 0; i < nums.size(); ++i) {
            right -= nums[i];
            if (left == right) {
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};