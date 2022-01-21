//--- Q: 1085. Sum of Digits in the Minimum Number

//--- method 1: simple finding sum of minv digits
class Solution {
public:
    int sumOfDigits(vector<int>& nums) {
        int minv = INT_MAX, res = 0;
        for (auto &num: nums) {
            minv = min(minv, num);
        }
        while (minv) {
            res += minv%10;
            minv /= 10;
        }
        return !(res&1);
    }
};