//--- Q: 747. Largest Number At Least Twice of Others

//--- method 1: linear processing
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (!nums.size()) {
            return -1;
        } else if (nums.size() == 1) {
            return 0;
        }
        int first = -1, second = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (first == -1 || nums[first] < nums[i]) {
                second = first;
                first = i;
            } else if (second == -1 || nums[second] < nums[i]) {
                second = i;
            }
        }
        return nums[second] * 2 <= nums[first] ? first : -1;
    }
};