//--- Q: 1470. Shuffle the Array

//--- method 1: O(1) space
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int j = 0;
        for (int i = n; i < nums.size(); ++i) {
            nums[i] |= (nums[j] <<= 10);
            ++j;
        }
        j = 0;
        for (int i = n; i < nums.size(); ++i) {
            nums[j] = (nums[i] >> 10);
            nums[j+1] = nums[i] & 1023;
            j += 2;
        }
        return nums;
    }
};
