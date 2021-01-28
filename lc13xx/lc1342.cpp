//--- Q: 1342. Number of Steps to Reduce a Number to Zero

//--- method 1: bit operation
class Solution {
public:
    int numberOfSteps (int num) {
        int res = 0;
        while (num) {
            res += (num&1) + 1;
            num >>= 1;
        }
        return !res ? 0 : res-1;
    }
};