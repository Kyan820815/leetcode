//--- Q: 0136. Single Number

//--- method 1: xor operation
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto &num: nums) {
            res ^= num;
        }
        return res;
    }
};