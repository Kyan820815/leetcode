//--- Q: 1018. Binary Prefix Divisible By 5

//--- method 1: mod 5 every step
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        vector<bool> res;
        for (auto &val: nums) {
            sum = (sum*2+val)%5;
            res.push_back(!sum);
        }
        return res;
    }
};