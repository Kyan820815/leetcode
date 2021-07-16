//--- Q: 0334. Increasing Triplet Subsequence

//--- method 1: find number > second_min
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int *first, *second, *third;
        first = second = third = nullptr;
        for (auto &num: nums) {
            if (!first || *first >= num) {
                first = &num;
            } else if (!second || *second >= num) {
                second = &num;
            } else {
                return true;
            }
        }
        return false;
    }
};