//--- Q: 0260. Single Number III

//--- method 1:  find the first different bit from left to right
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int diff = 0;
        for (auto &num: nums) {
            diff ^= num;
        }
        diff &= (~diff+1);
        int left = 0, right = 0;
        for (auto &num: nums) {
            if (diff & num) {
                left ^= num;
            } else {
                right ^= num;
            }
        }
        return {left, right};
    }
};