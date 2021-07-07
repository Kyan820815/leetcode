//--- Q: 0169. Majority Element

//--- method 1: maintain majority number, better
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int *max = nullptr;
        for (auto &num: nums) {
            if (max && *max == num) {
                ++cnt;
            } else if (!cnt) {
                cnt = 1;
                max = &num;
            } else {
                if (!--cnt) {
                    max = nullptr;
                }
            }
        }
        return *max;
    }
};