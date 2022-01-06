//--- Q: 0991. Broken Calculator

//--- method 1: find pattern
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int res = 0;
        while (target > startValue) {
            if (target&1) {
                ++res, ++target;
            }
            target >>= 1;
            ++res;
        }
        return res+startValue-target;
    }
};