//--- Q: 0137. Single Number II

//--- method 1: bit operation, O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, three = 0;
        for (auto &num: nums) {
            two |= (one&num);
            one ^= num;
            int share = one&two;
            one &= (~share);
            two &= (~share);

        }
        return one;
    }
};