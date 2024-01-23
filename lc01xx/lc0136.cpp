//--- Q: 0136. Single Number
//--- last written: 2023/07/14

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
