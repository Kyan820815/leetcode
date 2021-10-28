//--- Q: 0754. Reach a Number

//--- method 1: determine the diff odd or even
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int res = 0, step = 1, num = 0;
        while (num < target) {
            num += step++;
            ++res;
        }
        if ((num-target) % 2 == 0) {
            return res;
        } else {
            return step&1 ? res+1 : res+2;
        }
    }
};